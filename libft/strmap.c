/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:08:44 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:40:56 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[i] = (*f)(s[i]);
			++i;
		}
	}
	return (str);
}
