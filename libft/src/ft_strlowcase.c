/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:59:42 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/05 11:19:42 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
