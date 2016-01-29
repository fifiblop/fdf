/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:29:13 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/03 14:45:06 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s1[i++])
		size++;
	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest != NULL)
	{
		i = 0;
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
