/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:46:07 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/12 18:40:27 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#define TILE_SIZE 3

int		get_hauteur(t_map *map)
{
	t_coord a;
	int		max;

	a.y = 0;
	max = 0;
	while (a.y < map->lines)
	{
		a.x = 0;
		while (a.x < map->columns)
		{
			if (ft_abs(map->parse[a.y][a.x]) > max)
				max = ft_abs(map->parse[a.y][a.x]);
			a.x++;
		}
		a.y++;
	}
	max = (max * 10) / 100;
	return (max);
}

int		get_tile_size(t_mlx *mlx, t_map *map, int hauteur)
{
	int			tile;
	t_coord		top;
	t_coord		bottom;
	t_coord		left;
	t_coord		right;
	int			center_w;
	int			center_h;
	int			line;
	int			column;

	tile = 0;
	top.x = 0;
	top.y = 0;
	bottom.x = 0;
	bottom.y = 0;
	left.x = 0;
	left.y = 0;
	right.x = 0;
	right.y = 0;
	line = map->lines - 1;
	column = map->columns - 1;
	while ((top.x < mlx->width && top.y < mlx->height) &&
			(bottom.x < mlx->width && bottom.y < mlx->height) &&
			(left.x < mlx->width && left.y < mlx->height) &&
			(right.x < mlx->width && right.y < mlx->height) &&
			(top.x >= 0 && top.y >= 0) && (bottom.x >= 0 && bottom.y >= 0) &&
			(left.x >= 0 && left.y >= 0) && (right.x >= 0 && right.y >= 0))
	{
		center_w = (mlx->width / 2) - ((map->columns * tile) / 4);
		center_h = (mlx->height / 2) - ((map->lines * tile) / 2);
		top.x = (0 + 0) * (tile / 2) + center_h - (map->parse[0][0] * hauteur);
		top.y = (0 - 0) * tile + center_w;
		bottom.x = (column + line) * (tile / 2) + center_h - (map->parse[line][column] * hauteur);
		bottom.y = (column - line) * tile + center_w;
		left.x = (0 + map->lines) * (tile / 2) + center_h - (map->parse[line][0] * hauteur);
		left.y = (0 - map->lines) * tile + center_w;
		right.x = (column + 0) * (tile / 2) + center_h - (map->parse[0][column] * hauteur);
		right.y = (column - 0) * tile + center_w;
		tile++;
	}
	tile -= 2;
	return (tile);
}

void	isometric(t_mlx *mlx, t_map *map)
{
	t_coord	o;
	int		center_w;
	int		center_h;
	int		tile_s;
	int		hauteur;

	hauteur = get_hauteur(map);
	tile_s = get_tile_size(mlx, map, hauteur);
	center_w = (mlx->width / 2) - ((map->columns * tile_s) / 4);
	center_h = (mlx->height / 2) - ((map->lines * tile_s) / 2);
	map->print = (t_coord**)ft_memalloc(sizeof(t_coord*) * map->lines);
	o.y = 0;
	while (o.y < map->lines)
	{
		map->print[o.y] = (t_coord*)ft_memalloc(sizeof(t_coord) * map->columns);
		o.x = 0;
		while (o.x < map->columns)
		{
			map->print[o.y][o.x].x = (o.x + o.y) * (tile_s / 2) + center_h -
				(map->parse[o.y][o.x] * hauteur);
			map->print[o.y][o.x].y = (o.x - o.y) * tile_s + center_w;
			o.x++;
		}
		o.y++;
	}
}

void	normal(t_mlx *mlx, t_map *map)
{
	t_coord	o;
	int		center_w;
	int		center_h;

	center_w = (mlx->width / 2) - ((map->columns * TILE_SIZE) / 2);
	center_h = (mlx->height / 2) - ((map->lines * TILE_SIZE) / 2);
	map->print = (t_coord**)ft_memalloc(sizeof(t_coord*) * map->lines);
	o.y = 0;
	while (o.y < map->lines)
	{
		map->print[o.y] = (t_coord*)ft_memalloc(sizeof(t_coord) * map->columns);
		o.x = 0;
		while (o.x < map->columns)
		{
			map->print[o.y][o.x].y = o.x * TILE_SIZE + center_w;
			map->print[o.y][o.x].x = o.y * TILE_SIZE + center_h;
			o.x++;
		}
		o.y++;
	}
}

void	calc(t_mlx *mlx, t_map *map)
{
	(void)mlx;
	isometric(mlx, map);
}
