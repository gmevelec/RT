/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:08:38 by crenault          #+#    #+#             */
/*   Updated: 2014/03/26 18:36:39 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec			get_normal(t_obj obj, t_pt pos)
{
	t_vec			normal;
	t_pt			new_pt;
	static t_vec	(*f[])(t_obj, t_pt) =

	{
	sphere_norm, plane_norm, cyl_norm, cone_norm
	};
	if (obj.type - 1 > 4)
		obj.type = 1;
	new_pt = rotate_point_mat(pos, obj.pos, obj.rot_mat);
	normal = f[obj.type - 1](obj, new_pt);
	return (normal);
}

t_pt			get_intersection(t_ray ray, t_obj obj)
{
	double			t;
	t_vec			new_vec;
	t_pt			new_pt;
	t_pt			point;
	static double	(*f[])(t_pt, t_vec, t_obj) =

	{
	sphere_equ, plane_equ, cyl_equ, cone_equ
	};
	if (obj.type - 1 > 4)
		obj.type = 1;
	new_pt = rotate_point_mat(ray.start_pt, obj.pos, obj.rot_mat);
	new_vec = rotate_vector_mat(ray.vector, obj.rot_mat);
	new_vec = normalise_vector(new_vec);
	t = f[obj.type - 1](new_pt, new_vec, obj);
	point.x = ray.start_pt.x + ray.vector.x * t;
	point.y = ray.start_pt.y + ray.vector.y * t;
	point.z = ray.start_pt.z + ray.vector.z * t;
	return (point);
}

void			get_hit_obj(double *dist, t_pt *point, t_obj *obj, t_ray ray)
{
	int			i_obj;
	double		tmp_dist;
	t_pt		tmp_point;
	t_vec		tmp_vec;
	double		ang;

	obj->type = NONE;
	(*dist) = g()->cam.max_dist;
	i_obj = 0;
	while (i_obj < g()->nbr_objs)
	{
		tmp_point = get_intersection(ray, g()->objs[i_obj]);
		tmp_vec = create_vector(ray.start_pt, tmp_point);
		ang = dotproduct_vector(tmp_vec, ray.vector);
		tmp_dist = get_dist_points(tmp_point, ray.start_pt);
		if (tmp_dist < (*dist) && tmp_dist >= 0 && ang > 0)
		{
			(*dist) = tmp_dist;
			(*point) = tmp_point;
			(*obj) = g()->objs[i_obj];
		}
		i_obj++;
	}
}
