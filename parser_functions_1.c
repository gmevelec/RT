/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:30:57 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/24 15:46:12 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

void		ft_get_camera_resolution(char *line)
{
	int			i;
	char		**tmp;

	i = 0;
	while (line[i] == '\t')
		i++;
	tmp = ft_strsplit(&line[i], ',');
	g()->cam.res_x = ft_atoi(tmp[0]);
	g()->cam.res_y = ft_atoi(tmp[1]);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void		ft_get_camera_antialiasing(char *line)
{
	int			i;

	i = 0;
	while (line[i] == '\t')
		i++;
	g()->cam.antialiasing = ft_atoi(&line[i]);
}

void		ft_get_camera_max_depth(char *line)
{
	int			i;

	i = 0;
	while (line[i] == '\t')
		i++;
	g()->cam.max_depth = ft_atoi(&line[i]);
}

void		ft_get_camera_max_distance(char *line)
{
	int			i;

	i = 0;
	while (line[i] == '\t')
		i++;
	g()->cam.max_dist = ft_atoi(&line[i]);
}

void		ft_get_camera_position(char *line)
{
	int			i;
	char		**tmp;
	t_pt		pos;

	i = 0;
	while (line[i] == '\t')
		i++;
	tmp = ft_strsplit(&line[i], ',');
	pos.x = ft_atoi(tmp[0]);
	pos.y = ft_atoi(tmp[1]);
	pos.z = ft_atoi(tmp[2]);
	g()->cam.pos = pos;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}
