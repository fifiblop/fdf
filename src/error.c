/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:35:13 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/26 14:41:25 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	check_lines(char *filename)
{
	int		lines;
	int		a;
	int		nb_columns;

	lines = get_file_nbline(filename);
	if (lines == 0)
	{
		ft_putendl("error");
		exit(0);
	}
	nb_columns = get_file_nbcolumns(filename, 1);
	a = 1;
	while (a <= lines)
		if (get_file_nbcolumns(filename, a++) != nb_columns)
		{
			ft_putendl("error");
			exit(0);
		}
}

void	check_values(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j++]))
			{
				ft_putendl("error");
				exit(0);
			}
		}
		i++;
	}
}
