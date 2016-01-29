/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:06:10 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/03 14:35:28 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	size_t			i;

	value = (char)c;
	i = 0;
	while (i < len)
		((char*)b)[i++] = value;
	return (b);
}
