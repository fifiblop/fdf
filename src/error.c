/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:03:29 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/09 15:23:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
** Renvoi 1 si la chaine passee en parametre
** ne contient que des chifres
*/

int		ft_isnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_values(char *value)
{
	if (ft_isnum(ft_strtrim(value)) == 0)
	{
		ft_putendl("error");
		exit(1);
	}
}
