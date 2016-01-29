/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:42:13 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/05 11:01:27 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
