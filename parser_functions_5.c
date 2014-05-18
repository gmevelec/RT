/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:43:52 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/24 15:46:34 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

void		ft_get_object_color_info(char *line, int i)
{
	if (!ft_strncmp(line, "ambi:", 5))
		ft_get_object_ambi(line + 5, i);
	else if (!ft_strncmp(line, "diff:", 5))
		ft_get_object_diff(line + 5, i);
	else if (!ft_strncmp(line, "spec:", 5))
		ft_get_object_spec(line + 5, i);
}

void		ft_get_object_coef_ambi(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].mat.ambi_coef = ft_atoi(&line[j]);
}

void		ft_get_object_coef_diff(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].mat.diff_coef = ft_atoi(&line[j]);
}

void		ft_get_object_coef_spec(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].mat.spec_coef = ft_atoi(&line[j]);
}
