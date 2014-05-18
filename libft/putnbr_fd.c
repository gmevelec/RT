/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:30:03 by ygudusze          #+#    #+#             */
/*   Updated: 2014/03/27 17:04:56 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rec_print_number(int n, int fd)
{
	if (n >= 10)
	{
		ft_rec_print_number(n / 10, fd);
	}
	ft_putchar_fd('0' + n % 10, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n != -2147483648)
	{
		ft_rec_print_number(n, fd);
	}
	else
	{
		ft_putstr_fd("2147483648", fd);
	}
}
