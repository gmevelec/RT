/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:03:11 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 16:31:09 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			create_color(double red, double green, double blue)
{
	t_color		color;

	color.r = red;
	color.g = green;
	color.b = blue;
	return (color);
}

t_color			add_color(t_color color1, t_color color2)
{
	t_color		color;

	color.r = (color1.r > color2.r) ? color1.r : color2.r;
	color.g = (color1.g > color2.g) ? color1.g : color2.g;
	color.b = (color1.b > color2.b) ? color1.b : color2.b;
	return (color);
}

t_color			sub_color(t_color color1, t_color color2)
{
	t_color		color;

	color.r = (color1.r < color2.r) ? color1.r : color2.r;
	color.g = (color1.g < color2.g) ? color1.g : color2.g;
	color.b = (color1.b < color2.b) ? color1.b : color2.b;
	return (color);
}

t_color			perc_color(t_color color, double perc)
{
	t_color		color_perc;

	color_perc.r = color.r * (perc / 100);
	color_perc.g = color.g * (perc / 100);
	color_perc.b = color.b * (perc / 100);
	color_perc.r = (color_perc.r > 100) ? 100 : color_perc.r;
	color_perc.g = (color_perc.g > 100) ? 100 : color_perc.g;
	color_perc.b = (color_perc.b > 100) ? 100 : color_perc.b;
	return (color_perc);
}

t_color			cleaning_color(t_color color)
{
	t_color		col255;

	col255.r = (color.r > 100) ? 100 : color.r;
	col255.g = (color.g > 100) ? 100 : color.g;
	col255.b = (color.b > 100) ? 100 : color.b;
	col255.r = 255 * (color.r / 100);
	col255.g = 255 * (color.g / 100);
	col255.b = 255 * (color.b / 100);
	return (col255);
}
