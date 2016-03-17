/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:46:07 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/17 18:57:06 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		get_tile_size(t_mlx *mlx, t_map *map)
{
	int		t;
	int		size_w;
	int		xb;
	int		xd;

	t = 0;
	size_w = 0;
	(void)mlx;
	while (size_w < mlx->width)
	{
		xb = ((map->columns - 1) - 0) * t;
		xd = (0 - (map->lines - 1)) * t;
		size_w = ft_abs(xb) + ft_abs(xd);
		t++;
	}
	return (t - 2);
}

t_coord	center(t_mlx *mlx, t_map *map, int tile_size)
{
	t_coord c;
	int		xb;
	int		xd;
	int		ya;
	int		yc;

	xb = ((map->columns - 1) - 0) * tile_size;
	xd = (0 - (map->lines - 1)) * tile_size;
	ya = (0 + 0) * (tile_size / 2);
	yc = ((map->columns - 1) + (map->lines - 1)) * (tile_size / 2);
	c.x = (mlx->width / 2) - ((ft_abs(xb) - ft_abs(xd)) / 2);
	c.y = (mlx->height / 2) - ((ft_abs(yc) - ft_abs(ya)) / 2);
	return (c);
}

void	isometric(t_mlx *mlx, t_map *map)
{
	t_coord	o;
	t_coord b;
	int		tile;

	(void)mlx;
	map->print = (t_coord**)ft_memalloc(sizeof(t_coord*) * map->lines);
	tile = get_tile_size(mlx, map);
	b = center(mlx, map, tile);
	o.y = 0;
	while (o.y < map->lines)
	{
		o.x = 0;
		map->print[o.y] = (t_coord*)ft_memalloc(sizeof(t_coord) * map->columns);
		while (o.x < map->columns)
		{
			map->print[o.y][o.x].x = (o.x - o.y) * tile + b.x;
			map->print[o.y][o.x].y = (o.x + o.y) * (tile / 2) + b.y -
				(map->parse[o.y][o.x] * 2);
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
