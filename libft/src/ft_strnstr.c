/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:20:12 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/03 14:37:18 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		size;

	size = ft_strlen(s2);
	while (*s1 && n > 0)
	{
		if (!(ft_memcmp(s1, s2, size)) && size <= n)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (0);
}
