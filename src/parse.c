/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:31:54 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/22 17:39:45 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		get_file_nbline(char *filename)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(filename, O_RDONLY);
	nb_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
		free(line);
	}
	close(fd);
	return (nb_line);
}

int		get_file_nbcolumns(char *filename, int line_nb)
{
	int		fd;
	int		no_line;
	int		nb_columns;
	char	*line;
	char	**tab;

	fd = open(filename, O_RDONLY);
	nb_columns = 0;
	no_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		no_line++;
		if (no_line == line_nb)
		{
			tab = ft_strsplit(line, ' ');
			while (tab[nb_columns])
				nb_columns++;
			free_tab(tab);
		}
		free(line);
	}
	close(fd);
	return (nb_columns);
}

void	init_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**tab;
	t_coord	ind;

	map->parse = (int**)ft_memalloc(sizeof(int*) * map->lines);
	fd = open(filename, O_RDONLY);
	ind.y = 0;
	while (ind.y < map->lines)
	{
		ind.x = 0;
		map->parse[ind.y] = (int*)ft_memalloc(sizeof(int) * map->columns);
		get_next_line(fd, &line);
		tab = ft_strsplit(line, ' ');
		while (ind.x < map->columns)
		{
			check_values(tab);
			map->parse[ind.y][ind.x] = ft_atoi(tab[ind.x]);
			ind.x++;
		}
		free(line);
		free_tab(tab);
		ind.y++;
	}
	close(fd);
}

t_map	parse(char *filename)
{
	t_map	map;

	check_lines(filename);
	map.lines = get_file_nbline(filename);
	map.columns = get_file_nbcolumns(filename, 1);
	init_map(filename, &map);
	return (map);
}
