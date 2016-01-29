/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:08:19 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/11 17:29:50 by pdelefos         ###   ########.fr       */
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

char			*ft_itoa_base(int n, int base)
{
	char	*str;
	int		len;
	int		sign;

	if (base < 2 || base > 16)
		return (NULL);
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
			*--str = "0123456789ABCDEF"[ft_abs(n % base)];
			n = n / base;
		}
		if (sign)
			*--str = '-';
	}
	return (str);
}
