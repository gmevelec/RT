/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 13:53:11 by crenault          #+#    #+#             */
/*   Updated: 2014/03/22 14:02:27 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			ref_colors(t_pack pack, double last_ir, t_ray ray, int depth)
{
	t_iref		iref;
	t_ray		refl;
	t_ray		refr;
	t_color		tmp_color;

	iref = create_iref(last_ir, pack.obj.mat.index_refr, ray, pack.point);
	if (pack.obj.mat.reflect_coef > 0)
	{
		refl = get_refl_ray(iref, pack.normal);
		tmp_color = ray_trace(refl, depth + 1, pack.obj.mat.index_refr);
		tmp_color = perc_color(tmp_color, pack.obj.mat.reflect_coef);
		pack.color = moy_shine_color(pack.color, tmp_color);
	}
	if (pack.obj.mat.opacity_coef < 100)
	{
		refr = get_refr_ray(iref, pack.normal);
		tmp_color = ray_trace(refr, depth + 1, pack.obj.mat.index_refr);
		tmp_color = perc_color(tmp_color, 100 - pack.obj.mat.opacity_coef);
		pack.color = moy_shine_color(pack.color, tmp_color);
	}
	return (pack.color);
}
