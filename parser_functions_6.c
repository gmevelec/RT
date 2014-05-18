/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:46:05 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/24 15:46:38 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

void		ft_get_object_coef_info(char *line, int i)
{
	if (!ft_strncmp(line, "ambi:", 5))
		ft_get_object_coef_ambi(line + 5, i);
	else if (!ft_strncmp(line, "diff:", 5))
		ft_get_object_coef_diff(line + 5, i);
	else if (!ft_strncmp(line, "spec:", 5))
		ft_get_object_coef_spec(line + 5, i);
}

void		ft_get_object_index_ref(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].mat.index_refr = ft_atod(&line[j]);
}

void		ft_get_object_opacity_coef(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].mat.opacity_coef = ft_atoi(&line[j]);
}

void		ft_get_object_reflect_coef(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].mat.reflect_coef = ft_atoi(&line[j]);
}

void		ft_get_object_shininess(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].mat.shininess = ft_atod(&line[j]);
}
