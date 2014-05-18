/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 17:18:21 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 15:51:06 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>
#include <stdlib.h>

t_pt			create_point(double x, double y, double z)
{
	t_pt		point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

double			get_dist_points(t_pt p1, t_pt p2)
{
	double		distance;

	distance = hypot(hypot(p1.x - p2.x, p1.y - p2.y), p1.z - p2.z);
	distance = abs(distance);
	return (distance);
}
