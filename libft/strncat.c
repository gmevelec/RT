/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:12:06 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:40:54 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		++i;
	j = 0;
	while (j < n && s2[j])
	{
		s1[i] = s2[j];
		++i;
		++j;
	}
	s1[i] = '\0';
	return (s1);
}
