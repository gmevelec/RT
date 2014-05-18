/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 21:08:55 by crenault          #+#    #+#             */
/*   Updated: 2014/03/26 17:52:16 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>
#include <stdlib.h>

static int		nbr_softs_f(void)
{
	int			nbr_softs;
	int			tmp_s_s;
	int			i;

	i = 0;
	nbr_softs = 0;
	while (i < g()->nbr_lights)
	{
		nbr_softs += g()->lights[i].soft_shadows;
		tmp_s_s = g()->lights[i].soft_shadows;
		if (tmp_s_s != pow(sqrt(tmp_s_s), 2))
			error("The soft_shadows parameter is not an integer square root !");
		i++;
	}
	return (nbr_softs);
}

static void		mat_completion(t_lig light, double rot_mat[3][3])
{
	create_mat(cos(d_t_r(light.ang.x)), cos(d_t_r(light.ang.y)),
		cos(d_t_r(light.ang.z)), rot_mat);
}

static void		loop_ligs(int j, t_lig **tmp_ligs, int *i)
{
	int			sqrta;
	double		rot_mat[3][3];
	int			k;

	sqrta = sqrt(g()->lights[j].soft_shadows);
	k = 0;
	while (k < g()->lights[j].soft_shadows)
	{
		mat_completion(g()->lights[j], rot_mat);
		(*tmp_ligs)[*i].pos.x = g()->lights[j].pos.x + ((k % sqrta)
			* g()->lights[j].interval_soft) - (sqrta / 2);
		(*tmp_ligs)[*i].pos.y = g()->lights[j].pos.y;
		(*tmp_ligs)[*i].pos.z = g()->lights[j].pos.z + ((k / sqrta)
			* g()->lights[j].interval_soft) - (sqrta / 2);
		(*tmp_ligs)[*i].pos.x += -(((double)sqrta - 1) / 2.0
			* g()->lights[j].interval_soft);
		(*tmp_ligs)[*i].pos.z += -(((double)sqrta - 1) / 2.0
			* g()->lights[j].interval_soft);
		(*tmp_ligs)[*i].pos = rotate_point_mat((*tmp_ligs)[*i].pos,
			g()->lights[j].pos, rot_mat);
		(*tmp_ligs)[*i].color = perc_color(g()->lights[j].color, 100.0);
		(*tmp_ligs)[*i].coef_color = g()->lights[j].coef_color;
		(*i)++;
		k++;
	}
}

void			soft_shadows(void)
{
	int			j;
	int			i;
	int			nbr_softs;
	t_lig		*tmp_ligs;

	nbr_softs = nbr_softs_f();
	tmp_ligs = (t_lig*)malloc(sizeof(t_lig) * nbr_softs);
	j = 0;
	i = 0;
	while (j < g()->nbr_lights)
	{
		loop_ligs(j, &tmp_ligs, &i);
		j++;
	}
	if (g()->lights)
		free(g()->lights);
	g()->lights = tmp_ligs;
	g()->nbr_lights = nbr_softs;
}
