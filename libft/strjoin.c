/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:19:12 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:40:57 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (p)
	{
		ft_strcpy(p, s1);
		ft_strcat(p, s2);
	}
	return (p);
}
