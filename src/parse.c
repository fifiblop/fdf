/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:31:54 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/25 17:31:01 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

int		get_file_nbline(char *filename)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(filename, O_RDONLY);
	nb_line = 0;
	while (get_next_line(fd, &line) > 0)
		nb_line++;
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
			free(tab);
		}
	}
	close(fd);
	return (nb_columns);
}

void	check_lines(char *filename)
{
	int		lines;
	int		a;
	int		nb_columns;

	lines = get_file_nbline(filename);
	nb_columns = get_file_nbcolumns(filename, 1);
	a = 1;
	while (a <= lines)
		if (get_file_nbcolumns(filename, a++) != nb_columns)
		{
			ft_putendl("error");
			exit(0);
		}
}

t_map	init_map(char *filename)
{
	int		fd;
	char	*line;
	char	**tab;
	t_map	map;
	t_coord	ind;

	map.lines = get_file_nbline(filename);
	ft_putstr("--");
	ft_putnbr(map.lines);
	ft_putnl();
	map.columns = get_file_nbcolumns(filename, 1);
	map.parse = (int**)ft_memalloc(sizeof(int*) * map.lines);
	fd = open(filename, O_RDONLY);
	ind.x = 0;
	while (ind.x < map.lines)
	{
		ind.y = 0;
		map.parse[ind.x] = (int*)ft_memalloc(sizeof(int) * map.columns);
		get_next_line(fd, &line);
		tab = ft_strsplit(ft_strtrim(line), ' ');
		while (ind.y < map.columns)
		{
			map.parse[ind.x][ind.y] = ft_atoi(tab[ind.y]);
			ind.y++;
		}
		ind.x++;
	}
	return (map);
}

void	parse(char *filename)
{
	t_map	map;
	t_coord ind;

	check_lines(filename);
	map = init_map(filename);
	ind.x = 0;
	while (ind.x < map.lines)
	{
		ind.y = 0;
		while (ind.y < map.columns)
		{
			ft_putnbr(map.parse[ind.x][ind.y]);
			ft_putchar(' ');
			ind.y++;
		}
		ft_putnl();
		ind.x++;
	}
}
