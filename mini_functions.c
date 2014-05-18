/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:41:50 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 15:45:58 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <sys/time.h>
#include <math.h>
#include "libft/libft.h"

void			loading(double percent, int thread)
{
	int			i;

	g()->thrds[thread].loading = percent * 100;
	if (thread == 0)
	{
		ft_putstr("\033[s");
		i = 0;
		while (i < 4)
		{
			ft_putstr("[");
			ft_putnbr(g()->thrds[i].loading);
			ft_putstr(" / 100]  ");
			i++;
		}
		ft_putstr("                          ");
		ft_putstr("\033[u");
	}
}

double			d_t_r(double degree)
{
	double		radian;

	radian = degree * M_PI / 180;
	return (radian);
}

void			time_display(unsigned long timestamp)
{
	long long		time_in_micros;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time_in_micros = 1000000 * tv.tv_sec + tv.tv_usec;
	time_in_micros = time_in_micros - timestamp;
	ft_putstr("\033[32mPicture generated in: ");
	ft_putnbr(time_in_micros / 60 / 1000000);
	time_in_micros = time_in_micros % (60 * 1000000);
	ft_putstr(" minute(s) and ");
	ft_putnbr(time_in_micros / 1000000);
	time_in_micros = time_in_micros % 1000000;
	ft_putchar('.');
	ft_putnbr(time_in_micros);
	ft_putendl(" seconde(s)\033[0m\n");
}
