/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:29:27 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 17:00:33 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (dst <= src)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			++i;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = src[i - 1];
			--i;
		}
	}
	return (s1);
}
