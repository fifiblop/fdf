/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:24:58 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/02 11:00:57 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*str;
	int			size;

	str = s1;
	size = ft_strlen(s2);
	if (!*s2)
		return ((char*)s1);
	while (*str)
	{
		if (ft_strnequ(str, s2, size) == 1)
			return ((char*)str);
		str++;
	}
	return (0);
}
