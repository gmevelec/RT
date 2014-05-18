/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 19:31:43 by crenault          #+#    #+#             */
/*   Updated: 2014/03/27 16:58:10 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double		ft_tan(double x)
{
	double		result;

	result = ft_sin(x) / ft_cos(x);
	return (result);
}

double		ft_arctan(double x)
{
	double		a;
	double		b;
	int			n;
	double		result;

	b = 1.0;
	a = 1.0 / ft_sqrt(1.0 + (x * x));
	n = 1;
	while (n <= 11)
	{
		a = (a + b) / 2.0;
		b = ft_sqrt(a * b);
		n++;
	}
	result = x / (ft_sqrt(1.0 + (x * x)) * a);
	return (result);
}

double		ft_atan2(double y, double x)
{
	double		arctan;
	double		v_atan2;

	if (x != 0)
		arctan = ft_arctan(y / x);
	if (x > 0)
		v_atan2 = arctan;
	else if (y >= 0 && x < 0)
		v_atan2 = M_PI + arctan;
	else if (y < 0 && x < 0)
		v_atan2 = arctan - M_PI;
	else if (y > 0 && x == 0)
		v_atan2 = M_PI / 2;
	else
		v_atan2 = M_PI / -2;
	return (v_atan2);
}
