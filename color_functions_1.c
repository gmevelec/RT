/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:07:52 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 16:29:20 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_color			perc_rgb_color(t_color color, t_color perc)
{
	t_color		new_color;

	new_color.r = color.r * (perc.r / 100);
	new_color.g = color.g * (perc.g / 100);
	new_color.b = color.b * (perc.b / 100);
	return (new_color);
}

t_color			light_color(t_color lig, t_color col, double ang, t_color inte)
{
	t_color		color;

	color.r = (col.r / 100) * (lig.r / 100) * ang * inte.r;
	color.g = (col.g / 100) * (lig.g / 100) * ang * inte.g;
	color.b = (col.b / 100) * (lig.b / 100) * ang * inte.b;
	return (color);
}

t_color			shine_color(t_pack pck, t_color lig, double ang, t_mat mat)
{
	t_color		color;
	double		spec;

	if (ang > 0)
	{
		spec = powf(ang, pck.light_dist / 5) * (mat.reflect_coef / 100) * ang;
		color.r = pck.color.r + spec * lig.r * ((mat.spec.r / 100)
					* (mat.reflect_coef / 100));
		color.g = pck.color.g + spec * lig.g * ((mat.spec.g / 100)
					* (mat.reflect_coef / 100));
		color.b = pck.color.b + spec * lig.b * ((mat.spec.b / 100)
					* (mat.reflect_coef / 100));
		color.r = (color.r > 100) ? 100 : color.r;
		color.g = (color.g > 100) ? 100 : color.g;
		color.b = (color.b > 100) ? 100 : color.b;
		return (color);
	}
	return (pck.color);
}

t_color			sum_div_color(t_color color1, t_color color2, double div_)
{
	t_color		color;

	color.r = color1.r + color2.r / div_;
	color.g = color1.g + color2.g / div_;
	color.b = color1.b + color2.b / div_;
	return (color);
}

t_color			moy_shine_color(t_color color1, t_color color2)
{
	t_color		color;

	color.r = color1.r + (color2.r / 2);
	color.g = color1.g + (color2.g / 2);
	color.b = color1.b + (color2.b / 2);
	color.r = (color.r > 100) ? 100 : color.r;
	color.g = (color.g > 100) ? 100 : color.g;
	color.b = (color.b > 100) ? 100 : color.b;
	return (color);
}
