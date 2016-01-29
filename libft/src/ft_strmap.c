/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:59:29 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/03 14:52:11 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str)
	{
		while (*s)
			str[i++] = (*f)(*s++);
		str[i] = '\0';
	}
	return (str);
}
