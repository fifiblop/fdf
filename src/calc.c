/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:46:07 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/27 14:57:59 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#define TILE_SIZE 32

void	isometric(t_mlx *mlx, t_map *map)
{
	t_coord	o;
	int		center_w;
	int		center_h;

	center_w = (mlx->width / 2) - ((map->columns * TILE_SIZE) / 4);
	center_h = (mlx->height / 2) - ((map->lines * TILE_SIZE) / 2);
	map->print = (t_coord**)ft_memalloc(sizeof(t_coord*) * map->lines);
	o.y = 0;
	while (o.y < map->lines)
	{
		map->print[o.y] = (t_coord*)ft_memalloc(sizeof(t_coord) * map->columns);
		o.x = 0;
		while (o.x < map->columns)
		{
			map->print[o.y][o.x].x = (o.x + o.y) * (TILE_SIZE / 2) + center_h - (map->parse[o.y][o.x] * 3);
			map->print[o.y][o.x].y = (o.x - o.y) * TILE_SIZE + center_w;
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
	/*normal(mlx, map);*/
}
