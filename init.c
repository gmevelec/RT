/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:08:34 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 15:45:15 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <mlx.h>

void			init_data_addr(void)
{
	g()->cam.data_img = mlx_get_data_addr(g()->cam.img, &g()->e.bpp,
		&g()->e.sizeline, &g()->e.endian);
}
