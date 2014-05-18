/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:23:23 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 17:06:57 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_rec_add_number(char *s, int n)
{
	if (n >= 10)
	{
		ft_itoa_rec_add_number(s - 1, n / 10);
	}
	*s = '0' + n % 10;
}

static size_t	ft_itoa_count_digits(int n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	int		is_negative;

	is_negative = n >= 0 ? 0 : 1;
	if (is_negative)
		n = -n;
	if (n != -2147483648)
	{
		len = is_negative
			? ft_itoa_count_digits(n) + 1 : ft_itoa_count_digits(n);
		s = ft_strnew(len);
		if (s)
		{
			if (is_negative)
				s[0] = '-';
			ft_itoa_rec_add_number(s + len - 1, n);
		}
	}
	else
		s = ft_strdup("-2147483648");
	return (s);
}
