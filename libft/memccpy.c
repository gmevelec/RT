/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:11:05 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 16:58:45 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	uc;
	size_t			i;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == uc)
			return (s1 + i + 1);
		++i;
	}
	return (NULL);
}
