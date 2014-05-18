/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboulet <jboulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 10:32:20 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/23 12:24:52 by jboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(char *nb)
{
	char		**tmp;
	double		result;
	double		comma;
	int			i;

	if (!nb)
		return (0);
	result = 0;
	comma = 0;
	tmp = ft_strsplit(nb, '.');
	result += ft_atoi(tmp[0]);
	if (tmp[1])
		comma = (double)ft_atoi(tmp[1]);
	while (comma >= 1.0)
		comma /= 10.0;
	result += comma;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (result);
}
