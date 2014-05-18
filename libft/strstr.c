/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:28:00 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 17:03:44 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*p;
	size_t	len;

	p = (char *)s1;
	len = ft_strlen(s2);
	if (len > 0)
		while (*p)
		{
			if (ft_strncmp(p, s2, len) == 0)
				return (p);
			++p;
		}
	return (len > 0 ? NULL : p);
}
