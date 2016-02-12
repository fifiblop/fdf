/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:36:31 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/12 17:16:25 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
** Renvoi le nombre de lignes du ficher
*/

int		get_height(char *filename)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	free(line);
	close(fd);
	return (i);
}

/*
** Renvoi le nombre de caracteres de la ligne
** passe en parametre
*/

int		get_width(char *filename, int no_line)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = 0;
	j = 0;
	if (no_line < 1 || no_line > get_height(filename))
		return (0);
	fd = open(filename, O_RDONLY);
	while (j++ < no_line)
		get_next_line(fd, &line);
	tab = ft_strsplit(line, ' ');
	free(line);
	while (tab[i])
		i++;
	free(tab);
	close(fd);
	return (i);
}

/*
** initialise la hauteur et alloue la map
*/

t_map	init_grid(char *filename)
{
	t_map map;

	map.height = (int)ft_memalloc(sizeof(int));
	map.width = (int)ft_memalloc(sizeof(int));
	map.height = get_height(filename);
	map.grid = (int**)ft_memalloc(sizeof(int*) * map.height);
	return (map);
}

/*
** Parse le fichier passee en parametre
** et le stock dans un tableau d'int
** contenu dans une structure
*/

t_map	parsefile(char *filename)
{
	int		fd;
	char	*line;
	char	**tab;
	t_map	map;
	t_coord	a;

	map = init_grid(filename);
	fd = open(filename, O_RDONLY);
	map.width = get_width(filename, 1);
	a.x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map.grid[a.x] = (int*)ft_memalloc(sizeof(int) * map.width);
		tab = ft_strsplit(line, ' ');
		a.y = 0;
		while (tab[a.y])
		{
			check_values(tab[a.y]);
			map.grid[a.x][a.y] = ft_atoi(tab[a.y++]);
		}
		free(tab);
		a.x++;
	}
	close(fd);
	return (map);
}
