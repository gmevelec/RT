/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 20:33:27 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 15:44:33 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_vec			create_vector(t_pt point1, t_pt point2)
{
	t_vec		vector;

	vector.x = point2.x - point1.x;
	vector.y = point2.y - point1.y;
	vector.z = point2.z - point1.z;
	return (vector);
}

t_vec			normalise_vector(t_vec vec)
{
	t_vec		vector_norm;
	double		sqrta;

	sqrta = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	vector_norm.x = vec.x;
	vector_norm.y = vec.y;
	vector_norm.z = vec.z;
	if (sqrta != 0)
	{
		vector_norm.x = vec.x / sqrta;
		vector_norm.y = vec.y / sqrta;
		vector_norm.z = vec.z / sqrta;
	}
	return (vector_norm);
}

double			dotproduct_vector(t_vec vector1, t_vec vector2)
{
	double		dot;

	dot = vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	return (dot);
}
