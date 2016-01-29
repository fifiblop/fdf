/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:35:48 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/11 14:11:03 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	if (n < 0)
	{
		i = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		i = n;
	if (i < 10)
	{
		ft_putchar_fd(i + 48, fd);
		return ;
	}
	ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + 48, fd);
}
