/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 20:33:27 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 15:44:10 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_ray			create_ray(t_vec vector, t_pt start_pt)
{
	t_ray		ray;

	ray.vector = vector;
	ray.start_pt = start_pt;
	return (ray);
}

t_ray			get_refl_ray(t_iref iref, t_vec normal)
{
	t_ray		refl_ray;
	double		c1;

	c1 = -dotproduct_vector(normal, iref.ray.vector);
	refl_ray.vector.x = iref.ray.vector.x + (2 * normal.x * c1);
	refl_ray.vector.y = iref.ray.vector.y + (2 * normal.y * c1);
	refl_ray.vector.z = iref.ray.vector.z + (2 * normal.z * c1);
	refl_ray.vector = normalise_vector(refl_ray.vector);
	refl_ray.start_pt = iref.point;
	return (refl_ray);
}

t_ray			get_refr_ray(t_iref iref, t_vec normal)
{
	t_ray		refr_ray;
	double		n;
	double		c2;
	double		c1;

	c1 = -dotproduct_vector(normal, iref.ray.vector);
	n = iref.n1 / iref.n2;
	c2 = sqrt(1 - pow(n, 2) * (1 - pow(c1, 2)));
	refr_ray.vector.x = (n * iref.ray.vector.x) + (n * c1 - c2) * normal.x;
	refr_ray.vector.y = (n * iref.ray.vector.y) + (n * c1 - c2) * normal.y;
	refr_ray.vector.z = (n * iref.ray.vector.z) + (n * c1 - c2) * normal.z;
	refr_ray.vector = normalise_vector(refr_ray.vector);
	refr_ray.start_pt = iref.point;
	return (refr_ray);
}
