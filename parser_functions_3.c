/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:38:01 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/26 17:50:57 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"

void		ft_get_light_info(int fd, int i)
{
	char		*line;

	line = NULL;
	while (ft_strcmp(line, "\t}") && get_next_line(fd, &line))
	{
		if (!ft_strncmp(line, "\t\tposition:", 11))
			ft_get_light_pos(line + 11, i);
		else if (!ft_strncmp(line, "\t\tcolor:", 8))
			ft_get_light_color(line + 8, i);
		else if (!ft_strncmp(line, "\t\tcoef_color:", 13))
			ft_get_light_coef(line + 13, i);
		else if (!ft_strncmp(line, "\t\tsoft_shadows:", 15))
			ft_get_light_soft_shadows(line + 15, i);
		else if (!ft_strncmp(line, "\t\tinterval_soft:", 16))
			ft_get_light_interval_soft(line + 16, i);
		else if (!ft_strncmp(line, "\t\trotation:", 11))
			ft_get_light_rotation(line + 11, i);
		free(line);
	}
	if (ft_strcmp(line, "\t}"))
		free(line);
}

void		ft_get_lights(int fd, char *line)
{
	int			i;

	i = 0;
	g()->nbr_lights = ft_atoi(line);
	g()->lights = (t_lig*)malloc(sizeof(t_lig) * g()->nbr_lights);
	get_next_line(fd, &line);
	if (ft_strcmp(line, "{"))
		error("Error : Bab scene format");
	free(line);
	while (i < g()->nbr_lights && ft_strcmp(line, "}")
		&& get_next_line(fd, &line))
	{
		if (!ft_strcmp(line, "\t{"))
		{
			ft_get_light_info(fd, i);
			i++;
		}
		free(line);
	}
	g()->nbr_lights = i;
}

void		ft_get_object_type(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	if (!ft_strncmp(&line[j], "SPHERE", 6))
		g()->objs[i].type = SPHERE;
	else if (!ft_strncmp(&line[j], "PLANE", 4))
		g()->objs[i].type = PLANE;
	else if (!ft_strncmp(&line[j], "CYLINDRE", 8))
		g()->objs[i].type = CYLINDRE;
	else if (!ft_strncmp(&line[j], "CONE", 4))
		g()->objs[i].type = CONE;
	else if (!ft_strncmp(&line[j], "LIMITED_PLANE", 12))
		g()->objs[i].type = LIMITED_PLANE;
	else
		g()->objs[i].type = NONE;
}

void		ft_get_object_position(char *line, int i)
{
	char		**tmp;
	t_pt		pos;
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	tmp = ft_strsplit(&line[j], ',');
	pos.x = ft_atoi(tmp[0]);
	pos.y = ft_atoi(tmp[1]);
	pos.z = ft_atoi(tmp[2]);
	g()->objs[i].pos = pos;
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}

void		ft_get_object_rotation(char *line, int i)
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
	g()->objs[i].ang = ang;
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}
