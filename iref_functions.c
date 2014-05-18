/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iref_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:52:23 by crenault          #+#    #+#             */
/*   Updated: 2014/03/16 13:50:15 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_iref			create_iref(double n1, double n2, t_ray ray, t_pt point)
{
	t_iref		iref;

	iref.n1 = n1;
	iref.n2 = n2;
	iref.ray = ray;
	iref.point = point;
	return (iref);
}
