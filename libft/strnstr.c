/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:38:37 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 17:02:25 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*p;
	size_t	len;
	size_t	i;

	p = (char *)s1;
	len = ft_strlen(s2);
	i = 0;
	if (len > 0 && len <= n)
		while (i <= n - len && p[i])
		{
			if (ft_strncmp(p + i, s2, len) == 0)
				return (p + i);
			++i;
		}
	return (len > 0 ? NULL : p);
}
