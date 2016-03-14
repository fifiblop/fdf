/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:46:07 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/14 18:43:57 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	isometric(t_mlx *mlx, t_map *map)
{
	t_coord	o;
	t_fix	fix;

	fix = set_image(mlx, map);
	map->print = (t_coord**)ft_memalloc(sizeof(t_coord*) * map->lines);
	o.y = 0;
	while (o.y < map->lines)
	{
		map->print[o.y] = (t_coord*)ft_memalloc(sizeof(t_coord) * map->columns);
		o.x = 0;
		while (o.x < map->columns)
		{
			map->print[o.y][o.x].x = (o.x + o.y) * (fix.t / 2) +
				fix.c_h - (map->parse[o.y][o.x] * fix.h);
			map->print[o.y][o.x].y = (o.x - o.y) * fix.t + fix.c_w;
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
