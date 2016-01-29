/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:10 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/02 18:08:35 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = n * -1;
		ft_putchar('-');
	}
	else
		i = n;
	if (i < 10)
	{
		ft_putchar(i + 48);
		return ;
	}
	ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}
