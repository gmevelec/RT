/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:11:06 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:40:55 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s) * sizeof(*s))))
	{
		i = 0;
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			++i;
		}
	}
	return (str);
}
