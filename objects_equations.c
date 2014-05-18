/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:36:10 by crenault          #+#    #+#             */
/*   Updated: 2014/03/26 17:46:51 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

double			plane_equ(t_pt point, t_vec vector, t_obj plan)
{
	double		t;
	double		r1;
	double		r2;

	t = -(plan.ang.x * plan.pos.x + plan.ang.y * plan.pos.y + plan.ang.z
		* plan.pos.z);
	r1 = plan.ang.x * point.x + plan.ang.y * point.y + plan.ang.z
		* point.z + t;
	r2 = plan.ang.x * vector.x + plan.ang.y * vector.y + plan.ang.z * vector.z;
	t = -(r1 / r2);
	return (t);
}

double			sphere_equ(t_pt point, t_vec vector, t_obj sphere)
{
	double			t;
	double			t2;
	t_equ			equ;
	double			det;

	equ.a = dotproduct_vector(vector, vector);
	equ.b = 2 * (vector.x * (point.x - sphere.pos.x) + vector.y *
		(point.y - sphere.pos.y) + vector.z * (point.z - sphere.pos.z));
	equ.c = (pow((point.x - sphere.pos.x), 2) + pow((point.y - sphere.pos.y), 2)
			+ pow((point.z - sphere.pos.z), 2)) - pow(sphere.size, 2);
	det = pow(equ.b, 2) - 4 * equ.a * equ.c;
	t2 = 0;
	t = (-equ.b + sqrt(det)) / (2 * equ.a);
	if (det > 0)
		t2 = (-equ.b - sqrt(det)) / (2 * equ.a);
	if (det > 0 && t2 < t)
		t = t2;
	return (t);
}

double			cone_equ(t_pt point, t_vec vector, t_obj cone)
{
	double			t;
	double			t2;
	t_equ			equ;
	double			det;

	equ.a = vector.x * vector.x - vector.y * vector.y + vector.z * vector.z;
	equ.b = 2 * (vector.x * (point.x - cone.pos.x) - vector.y *
		(point.y - cone.pos.y) + vector.z * (point.z - cone.pos.z));
	equ.c = (pow((point.x - cone.pos.x), 2) - pow((point.y - cone.pos.y), 2)
			+ pow((point.z - cone.pos.z), 2)) - pow(cone.size, 2);
	det = pow(equ.b, 2) - 4 * equ.a * equ.c;
	t2 = 0;
	t = (-equ.b + sqrt(det)) / (2 * equ.a);
	if (det > 0)
		t2 = (-equ.b - sqrt(det)) / (2 * equ.a);
	if (det > 0 && t2 < t)
		t = t2;
	return (t);
}

double			cyl_equ(t_pt point, t_vec vector, t_obj cyl)
{
	double			t;
	double			t2;
	t_equ			equ;
	double			det;

	equ.a = vector.x * vector.x + vector.z * vector.z;
	equ.b = 2 * (vector.x * (point.x - cyl.pos.x) + vector.z
			* (point.z - cyl.pos.z));
	equ.c = (pow((point.x - cyl.pos.x), 2) + pow((point.z - cyl.pos.z), 2))
			- pow(cyl.size, 2);
	det = pow(equ.b, 2) - 4 * equ.a * equ.c;
	t2 = 0;
	t = (-equ.b + sqrt(det)) / (2 * equ.a);
	if (det > 0)
		t2 = (-equ.b - sqrt(det)) / (2 * equ.a);
	if (det > 0 && t2 < t)
		t = t2;
	return (t);
}
