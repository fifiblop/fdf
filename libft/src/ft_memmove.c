/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:41:13 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/11 14:14:13 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		tab[len];

	i = 0;
	while (i < len)
	{
		tab[i] = ((char*)(src))[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char*)(dst))[i] = tab[i];
		i++;
	}
	return (dst);
}
