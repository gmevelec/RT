/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 12:49:07 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 16:26:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			*render_picture(void *plus)
{
	int			y;
	int			x;
	t_color		color;

	y = (size_t)plus;
	while (y < g()->cam.res_y)
	{
		x = 0;
		loading(y / (double)g()->cam.res_y, (size_t)plus);
		while (x < g()->cam.res_x)
		{
			color = antia_function(y, x, g()->cam.antialiasing);
			put_pixel(g()->cam.data_img, y, x, color);
			x++;
		}
		y += 4;
	}
	return (NULL);
}

t_color			get_intensity(t_pt point, t_pt lig_pt, t_obj obj, t_pack pack)
{
	t_vec		tmp_vec;
	t_ray		tmp_ray;
	t_pt		tmp_point;
	double		obj_dist;
	double		ang;

	tmp_vec = normalise_vector(create_vector(point, lig_pt));
	tmp_ray = create_ray(tmp_vec, point);
	tmp_point = get_intersection(tmp_ray, obj);
	ang = dotproduct_vector(create_vector(tmp_point, lig_pt), tmp_vec);
	obj_dist = get_dist_points(tmp_point, lig_pt);
	if (obj_dist < pack.light_dist && ang > 0)
	{
		pack.intensity = sub_color(pack.intensity, obj.mat.spec);
		pack.intensity = perc_color(pack.intensity, 100 - obj.mat.opacity_coef);
	}
	return (pack.intensity);
}

t_color			get_perceived_color(t_pack pck, t_pt p, t_lig light, t_obj obj)
{
	t_vec		light_vec;
	t_vec		tmp_normal;
	t_color		tmp_color;
	double		ang;

	light_vec = create_vector(p, light.pos);
	light_vec = normalise_vector(light_vec);
	tmp_normal = normalise_vector(pck.normal);
	if (obj.type != PLANE)
		light_vec = rotate_vector_mat(light_vec, obj.rot_mat);
	ang = dotproduct_vector(tmp_normal, light_vec);
	tmp_color = create_color(0, 0, 0);
	if (ang > 0)
		tmp_color = light_color(light.color, obj.mat.diff, ang, pck.intensity);
	tmp_color = perc_color(tmp_color, obj.mat.opacity_coef);
	pck.color = tmp_color;
	tmp_color = shine_color(pck, light.color, ang, obj.mat);
	tmp_color = perc_rgb_color(tmp_color, pck.intensity);
	return (tmp_color);
}

t_color			foreach_light(t_pt pt, t_vec nrm, t_obj obj)
{
	int			i_lig;
	int			i_obj;
	t_pack		pack;

	i_lig = 0;
	pack.color = create_color(0, 0, 0);
	while (i_lig < g()->nbr_lights)
	{
		pack.intensity = perc_color(g()->lights[i_lig].color, 100);
		pack.light_dist = get_dist_points(g()->lights[i_lig].pos, pt);
		i_obj = 0;
		while (i_obj < g()->nbr_objs)
		{
			pack.intensity = get_intensity(pt, g()->lights[i_lig].pos,
							g()->objs[i_obj], pack);
			i_obj++;
		}
		pack.normal = nrm;
		pack.color = perc_color(add_color(pack.color, get_perceived_color(pack,
			pt, g()->lights[i_lig], obj)), g()->lights[i_lig].coef_color);
		i_lig++;
	}
	return (pack.color);
}

t_color			ray_trace(t_ray ray, int depth, double last_ir)
{
	double		dist;
	t_pack		pack;

	get_hit_obj(&dist, &pack.point, &pack.obj, ray);
	if (pack.obj.type != NONE)
	{
		pack.normal = get_normal(pack.obj, pack.point);
		pack.color = foreach_light(pack.point, pack.normal, pack.obj);
		if (depth < g()->cam.max_depth)
			pack.color = ref_colors(pack, last_ir, ray, depth);
	}
	else
		pack.color = create_color(0, 0, 0);
	return (pack.color);
}
