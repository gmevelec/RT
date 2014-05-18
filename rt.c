/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:29:56 by crenault          #+#    #+#             */
/*   Updated: 2014/03/27 16:51:13 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <time.h>
#include <math.h>
#include <mlx.h>
#include <sys/time.h>
#include "libft/libft.h"

t_gen			*g(void)
{
	static t_gen	*gen = NULL;

	if (gen == NULL)
		gen = (t_gen *)malloc(sizeof(t_gen));
	return (gen);
}

static void		rot_mats(void)
{
	int			i;
	int			antia;

	i = 0;
	antia = g()->cam.antialiasing;
	if (antia != pow(sqrt(antia), 2))
		error("The antialiasing parameter is not an integer square root !");
	while (i < g()->nbr_objs)
	{
		create_mat(cos(d_t_r(g()->objs[i].ang.x)),
			cos(d_t_r(g()->objs[i].ang.y)), cos(d_t_r(g()->objs[i].ang.z)),
			g()->objs[i].rot_mat);
		i++;
	}
	create_mat(cos(d_t_r(g()->cam.ang.x)), cos(d_t_r(g()->cam.ang.y)),
		cos(d_t_r(g()->cam.ang.z)), g()->cam.rot_mat);
}

int				expose_hook(void)
{
	unsigned long	time_in_micros;
	struct timeval	tv;

	if (g()->reload_screen)
	{
		ft_classic_parser(g()->filename);
		rot_mats();
		soft_shadows();
		ft_putstr("\x1B[?25l");
		g()->reload_screen = FALSE;
		gettimeofday(&tv, NULL);
		time_in_micros = 1000000 * tv.tv_sec + tv.tv_usec;
		launch_threads();
		time_display(time_in_micros);
		ft_putstr("\x1B[?25h");
	}
	mlx_put_image_to_window(g()->e.mlx, g()->e.win, g()->cam.img, 0, 0);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
		error("Usage: ./RT file");
	g()->reload_screen = TRUE;
	g()->filename = ft_strdup(argv[1]);
	ft_classic_parser(g()->filename);
	g()->e.mlx = mlx_init();
	if (!g()->e.mlx)
		error("Mlx can't init !");
	g()->e.win = mlx_new_window(g()->e.mlx, g()->cam.res_x,
		g()->cam.res_y, "RT window");
	g()->cam.img = mlx_new_image(g()->e.mlx, g()->cam.res_x, g()->cam.res_y);
	g()->thrds = (t_threads*)malloc(sizeof(t_threads) * 4);
	mlx_hook(g()->e.win, 3, 2, &key_relea, &g()->e);
	mlx_hook(g()->e.win, 2, 3, &key_press, &g()->e);
	init_data_addr();
	mlx_expose_hook(g()->e.win, expose_hook, NULL);
	mlx_loop(g()->e.mlx);
	return (0);
}
