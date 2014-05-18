/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:21:27 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/24 15:46:44 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

void		ft_get_light_soft_shadows(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->lights[i].soft_shadows = ft_atoi(&line[j]);
}

void		ft_get_light_interval_soft(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->lights[i].interval_soft = ft_atod(&line[j]);
}

void		ft_get_light_rotation(char *line, int i)
{
	int			j;
	char		**tmp;
	t_ang		ang;

	j = 0;
	while (line[j] == '\t')
		j++;
	tmp = ft_strsplit(&line[j], ',');
	ang.x = ft_atod(tmp[0]);
	ang.y = ft_atod(tmp[1]);
	ang.z = ft_atod(tmp[2]);
	g()->lights[i].ang = ang;
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}
