/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:52:31 by crenault          #+#    #+#             */
/*   Updated: 2014/03/20 02:02:15 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			launch_threads(void)
{
	pthread_create(&g()->thrds[0].thread, NULL, render_picture, (void*)0);
	pthread_create(&g()->thrds[1].thread, NULL, render_picture, (void*)1);
	pthread_create(&g()->thrds[2].thread, NULL, render_picture, (void*)2);
	pthread_create(&g()->thrds[3].thread, NULL, render_picture, (void*)3);
	pthread_join(g()->thrds[0].thread, NULL);
	pthread_join(g()->thrds[1].thread, NULL);
	pthread_join(g()->thrds[2].thread, NULL);
	pthread_join(g()->thrds[3].thread, NULL);
}
