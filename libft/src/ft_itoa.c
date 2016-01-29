/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:32:27 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/05 10:27:03 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static	int		ft_nblen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_nblen(n);
	sign = (n < 0 ? 1 : 0);
	str = NULL;
	str = (char*)malloc(sizeof(char) * (len + sign + 1));
	if (str)
	{
		str = str + len + sign;
		*str = '\0';
		if (n == 0)
			*--str = '0';
		while (n != 0)
		{
			*--str = ft_abs(n % 10) + 48;
			n = n / 10;
		}
		if (sign)
			*--str = '-';
	}
	return (str);
}
