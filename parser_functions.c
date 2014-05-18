/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 18:33:27 by crenault          #+#    #+#             */
/*   Updated: 2014/03/25 15:05:51 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"

void		ft_get_object_info(int fd, int i, char *line)
{
	while (ft_strcmp(line, "\t}") && get_next_line(fd, &line))
	{
		if (!ft_strncmp(line, "\t\ttype:", 7))
			ft_get_object_type(line + 7, i);
		else if (!ft_strncmp(line, "\t\tposition:", 11))
			ft_get_object_position(line + 11, i);
		else if (!ft_strncmp(line, "\t\trotation:", 11))
			ft_get_object_rotation(line + 11, i);
		else if (!ft_strncmp(line, "\t\tsize:", 7))
			ft_get_object_size(line + 7, i);
		else if (!ft_strncmp(line, "\t\tcolor_", 8))
			ft_get_object_color_info(line + 8, i);
		else if (!ft_strncmp(line, "\t\tcoef_", 7))
			ft_get_object_coef_info(line + 7, i);
		else if (!ft_strncmp(line, "\t\tindex_ref:", 12))
			ft_get_object_index_ref(line + 12, i);
		else if (!ft_strncmp(line, "\t\topacity_coef:", 15))
			ft_get_object_opacity_coef(line + 15, i);
		else if (!ft_strncmp(line, "\t\treflect_coef:", 15))
			ft_get_object_reflect_coef(line + 15, i);
		else if (!ft_strncmp(line, "\t\tshininess:", 12))
			ft_get_object_shininess(line + 12, i);
		free(line);
	}
}

void		ft_get_objects(int fd, char *line)
{
	int			i;

	i = 0;
	g()->nbr_objs = ft_atoi(line);
	g()->objs = (t_obj*)malloc(sizeof(t_obj) * g()->nbr_objs);
	get_next_line(fd, &line);
	if (ft_strcmp(line, "{"))
		error("Error : Bab scene format");
	free(line);
	while (i < g()->nbr_objs && ft_strcmp(line, "}")
		&& get_next_line(fd, &line))
	{
		if (!ft_strcmp(line, "\t{"))
		{
			ft_get_object_info(fd, i, line);
			i++;
		}
		free(line);
	}
	g()->nbr_objs = i;
}

void		ft_classic_parser(const char *file_name)
{
	int			fd;
	char		*line;

	if ((fd = open(file_name, O_RDONLY)) == -1
		|| strncmp(file_name + ft_strlen(file_name) - 4, ".scn", 4))
		error("Filename");
	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp(line, "camera:"))
			ft_get_camera(fd);
		else if (!ft_strncmp(line, "lights: ", 8))
			ft_get_lights(fd, line + 9);
		else if (!ft_strncmp(line, "objects: ", 9))
			ft_get_objects(fd, line + 10);
		if (line)
			free(line);
	}
	free(line);
	close(fd);
	get_next_line(-42, NULL);
}
