/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antia_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 11:52:43 by crenault          #+#    #+#             */
/*   Updated: 2014/03/26 17:42:53 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_color			antia_function(int y, int x, int antia)
{
	t_color		tmp_color;
	t_color		color;
	int			i;
	int			j;
	double		sqrta;

	color = create_color(0, 0, 0);
	i = 0;
	sqrta = sqrt(antia);
	while (i < sqrta)
	{
		j = 0;
		while (j < sqrta)
		{
			tmp_color = get_pixel_color(x - (1 / -(i - sqrta)),
						y - (1 / -(j - sqrta)));
			color.r += tmp_color.r / antia;
			color.g += tmp_color.g / antia;
			color.b += tmp_color.b / antia;
			j++;
		}
		i++;
	}
	return (color);
}
