/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:26:19 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 17:02:47 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*q;
	char	d;

	p = (char *)s;
	q = NULL;
	d = (char)c;
	while (*p || d == '\0')
	{
		if (*p == d)
		{
			q = p;
			if (d == '\0')
				return (q);
		}
		++p;
	}
	return (q);
}
