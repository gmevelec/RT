/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:24:14 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 17:01:50 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	d;

	p = (char *)s;
	d = (char)c;
	while (*p || d == '\0')
	{
		if (*p == d)
			return (p);
		++p;
	}
	return (NULL);
}
