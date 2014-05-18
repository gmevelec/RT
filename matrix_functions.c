/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 18:07:16 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 16:12:13 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		create_mat(double cx, double cy, double cz, double mat[3][3])
{
	double		sinx;
	double		siny;
	double		sinz;

	sinx = sin(acos(cx));
	siny = sin(acos(cy));
	sinz = sin(acos(cz));
	mat[0][0] = cy * cz;
	mat[0][1] = -cy * sinz;
	mat[0][2] = -siny;
	mat[1][0] = -sinx * siny * cz + cx * sinz;
	mat[1][1] = sinx * siny * sinz + cx * cz;
	mat[1][2] = -sinx * cy;
	mat[2][0] = cx * siny * cz + sinx * sinz;
	mat[2][1] = -cx * siny * sinz + sinx * cz;
	mat[2][2] = cx * cy;
}

t_vec		rotate_vector_mat(t_vec vector, double mat[3][3])
{
	t_vec		new;

	new.x = vector.x * mat[0][0] + vector.y * mat[0][1] + vector.z * mat[0][2];
	new.y = vector.x * mat[1][0] + vector.y * mat[1][1] + vector.z * mat[1][2];
	new.z = vector.x * mat[2][0] + vector.y * mat[2][1] + vector.z * mat[2][2];
	return (new);
}

t_pt		rotate_point_mat(t_pt origin, t_pt center, double mat[3][3])
{
	t_pt		new;

	new.x = (origin.x - center.x) * mat[0][0] + (origin.y - center.y)
			* mat[0][1] + (origin.z - center.z) * mat[0][2];
	new.y = (origin.x - center.x) * mat[1][0] + (origin.y - center.y)
			* mat[1][1] + (origin.z - center.z) * mat[1][2];
	new.z = (origin.x - center.x) * mat[2][0] + (origin.y - center.y)
			* mat[2][1] + (origin.z - center.z) * mat[2][2];
	new.x += center.x;
	new.y += center.y;
	new.z += center.z;
	return (new);
}
