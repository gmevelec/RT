/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:17:22 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:40:48 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	p = ft_strnew(len);
	if (p)
		ft_strncpy(p, s + start, len);
	return (p);
}
