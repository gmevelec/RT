/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:41:40 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/24 15:46:28 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

void		ft_get_object_size(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->objs[i].size = ft_atoi(&line[j]);
}

void		ft_get_object_ambi(char *line, int i)
{
	char		**tmp;
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	tmp = ft_strsplit(&line[j], ',');
	g()->objs[i].mat.ambi =
	create_color(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}

void		ft_get_object_diff(char *line, int i)
{
	char		**tmp;
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	tmp = ft_strsplit(&line[j], ',');
	g()->objs[i].mat.diff =
	create_color(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}

void		ft_get_object_spec(char *line, int i)
{
	char		**tmp;
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	tmp = ft_strsplit(&line[j], ',');
	g()->objs[i].mat.spec =
	create_color(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}
