/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:05:58 by crenault          #+#    #+#             */
/*   Updated: 2014/03/26 17:51:41 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <mlx.h>

static unsigned int		rgb_to_hex(t_env e, int r, int g, int b)
{
	unsigned int	hexa;

	hexa = ((r & 0xFF) << e.bpp / 2) + ((g & 0xFF) << e.bpp / 4) + (b & 0xFF);
	return (hexa);
}

void					put_pixel(char *data, int y, int x, t_color color)
{
	unsigned int	hex_color;
	unsigned int	hexa;
	int				i;

	hexa = rgb_to_hex(g()->e, color.r, color.g, color.b);
	hex_color = mlx_get_color_value(g()->e.mlx, hexa);
	i = y * g()->e.sizeline + (g()->e.bpp / 8) * x;
	data[i] = (hex_color & 0xFF);
	data[i + 1] = (hex_color & 0xFF00) >> 8;
	data[i + 2] = (hex_color & 0xFF0000) >> 16;
}

t_pt					create_pixel_pt(double x, double y)
{
	t_pt		point;

	point.x = x - (g()->cam.res_x / 2) + g()->cam.pos.x;
	point.y = -(y - (g()->cam.res_y / 2)) + g()->cam.pos.y;
	point.z = g()->cam.focale + g()->cam.pos.z;
	return (point);
}

t_color					get_pixel_color(double x, double y)
{
	t_ray		ray;
	t_vec		tmp_vec;
	t_pt		pixel;
	t_color		color;

	pixel = create_pixel_pt(x, y);
	tmp_vec = create_vector(g()->cam.pos, pixel);
	tmp_vec = normalise_vector(tmp_vec);
	tmp_vec = rotate_vector_mat(tmp_vec, g()->cam.rot_mat);
	ray = create_ray(tmp_vec, g()->cam.pos);
	color = ray_trace(ray, 0, 1);
	color = cleaning_color(color);
	return (color);
}
