/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:57:14 by crenault          #+#    #+#             */
/*   Updated: 2014/03/24 15:49:08 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <unistd.h>

int				key_relea(int keycode)
{
	if (keycode == 65307)
		_exit(0);
	else if (keycode == 65293)
	{
		g()->reload_screen = TRUE;
		expose_hook();
	}
	return (0);
}

int				key_press(int keycode)
{
	(void)keycode;
	return (0);
}
