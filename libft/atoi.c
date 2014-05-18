/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:52:57 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:41:19 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		mark;
	int		nb;

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
