/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:33:53 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/24 15:50:28 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void		ft_get_camera_rotation(char *line)
{
	int			i;
	char		**tmp;
	t_ang		ang;

	i = 0;
	while (line[i] == '\t')
		i++;
	tmp = ft_strsplit(&line[i], ',');
	ang.x = ft_atod(tmp[0]);
	ang.y = ft_atod(tmp[1]);
	ang.z = ft_atod(tmp[2]);
	g()->cam.ang = ang;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void		ft_get_camera(int fd)
{
	char		*line;

	get_next_line(fd, &line);
	if (ft_strcmp(line, "{"))
		error("Error : Bab scene format");
	free(line);
	while (ft_strcmp(line, "}") && get_next_line(fd, &line))
	{
		if (!ft_strncmp(line, "\tresolution:", 12))
			ft_get_camera_resolution(line + 12);
		else if (!ft_strncmp(line, "\tantialiasing:", 14))
			ft_get_camera_antialiasing(line + 14);
		else if (!ft_strncmp(line, "\tmax_depth:", 11))
			ft_get_camera_max_depth(line + 11);
		else if (!ft_strncmp(line, "\tmax_distance:", 14))
			ft_get_camera_max_distance(line + 14);
		else if (!ft_strncmp(line, "\tposition:", 10))
			ft_get_camera_position(line + 10);
		else if (!ft_strncmp(line, "\trotation:", 10))
			ft_get_camera_rotation(line + 10);
		free(line);
	}
	g()->cam.focale = (g()->cam.res_x / 2.0) / tan(45.0 / 2.0);
}

void		ft_get_light_pos(char *line, int i)
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
	g()->lights[i].pos = pos;
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}

void		ft_get_light_coef(char *line, int i)
{
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	g()->lights[i].coef_color = ft_atoi(&line[j]);
}

void		ft_get_light_color(char *line, int i)
{
	char		**tmp;
	int			j;

	j = 0;
	while (line[j] == '\t')
		j++;
	tmp = ft_strsplit(&line[j], ',');
	g()->lights[i].color =
	create_color(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
}
