/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:52:57 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:40:42 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long(const char *str)
{
	int		mark;
	long	nb;

	mark = 1;
	nb = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\r'
				|| *str == '\v' || *str == '\f' || *str == '\n'))
		++str;
	if ((*str == '-' || *str == '+')
			&& (*(str + 1) >= '0' && *(str + 1) <= '9'))
	{
		mark = *str == '-' ? -1 : 1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		++str;
	}
	return (mark * nb);
}
