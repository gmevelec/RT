/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartine <vmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:54:18 by vmartine          #+#    #+#             */
/*   Updated: 2014/03/27 16:55:49 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		if (*alst && (*alst)->next)
		{
			ft_lstdel(&((*alst)->next), del);
			(*alst)->next = NULL;
		}
		ft_lstdelone(alst, del);
	}
}
