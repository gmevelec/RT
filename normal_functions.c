/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:57:22 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/21 13:21:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		sphere_norm(t_obj obj, t_pt pos)
{
	t_vec		vect;

	vect = create_vector(obj.pos, pos);
	return (vect);
}

t_vec		cyl_norm(t_obj obj, t_pt pos)
{
	t_vec		vect;

	vect = create_vector(obj.pos, pos);
	vect.y = 0;
	return (vect);
}

t_vec		cone_norm(t_obj obj, t_pt pos)
{
	t_vec		vect;

	vect = create_vector(obj.pos, pos);
	vect.y *= -1;
	return (vect);
}

t_vec		plane_norm(t_obj obj, t_pt pos)
{
	t_vec		vect;

	(void)pos;
	vect.x = obj.ang.x;
	vect.y = obj.ang.y;
	vect.z = obj.ang.z;
	return (vect);
}
