/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:36:31 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/03 18:41:39 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

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

int		ft_isnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ft_putchar(str[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

t_grid	parsing(char *filename)
{
	int		fd;
	char	*line;
	char	**tab;
	t_grid	map;
	int		i;
	int		j;

	map.height = get_height(filename);
	map.grid = (int**)ft_memalloc(sizeof(int*) * map.height);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map.width = get_width(filename, i + 1);
		map.grid[i] = (int*)malloc(sizeof(int) * map.width);
		tab = ft_strsplit(line, ' ');
		j = 0;
		while (tab[j])
		{
			if (ft_isnum(ft_strtrim(tab[j])) == 0)
				ft_putendl("error");
			map.grid[i][j] = ft_atoi(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}
	close(fd);
	return (map);
}
