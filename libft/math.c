/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 00:47:02 by crenault          #+#    #+#             */
/*   Updated: 2014/03/27 16:56:39 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double		ft_sin(double x)
{
	double		cos_result;

	cos_result = ft_cos(x - (M_PI / 2));
	return (cos_result);
}

double		ft_cos(double cx)
{
	double	r;
	double	s;
	int		i;

	r = cx * cx;
	s = 42.0;
	i = 10;
	while (--i >= 1)
		s = 4.0 * i - 2.0 + (-r) / s;
	s *= s;
	return ((s - r) / (s + r));
}

int			ft_fact(int n)
{
	int		fact;
	int		i;

	fact = 1;
	i = 1;
	while (++i < n)
		fact *= i;
	return (fact);
}

double		ft_pow(double x, int y)
{
	double	temp;

	if (!y)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	if (y)
		return (x * temp * temp);
	else
		return ((temp * temp) / x);
}

double		ft_sqrt(double nb)
{
	double	calc;
	double	diff;

	if (nb == 0.0 || nb == 1.0)
		return (nb);
	calc = nb;
	diff = calc;
	calc = 0.5 * (calc + nb / calc);
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}
