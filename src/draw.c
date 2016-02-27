/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:55:43 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/27 12:33:08 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void	put_pixel_to_image(t_img *img, int y, int x, int color)
{
	((int*)(img->addr))[y * img->mlx_width + x] = color;
}

void	init_line(t_line *line, t_coord *a, t_coord *b)
{
	line->steep = 0;
	if (ft_abs(a->x - b->x) < ft_abs(a->y - b->y))
	{
		ft_swap(&a->x, &a->y);
		ft_swap(&b->x, &b->y);
		line->steep = 1;
	}
	if (a->x > b->x)
	{
		ft_swap(&a->x, &b->x);
		ft_swap(&a->y, &b->y);
	}
	line->dx = b->x - a->x;
	line->dy = b->y - a->y;
	line->derror = ft_abs(line->dy) * 2;
	line->error = 0;
	line->pt.x = a->x;
	line->pt.y = a->y;
}

void	draw_lines(t_img *img, t_coord a, t_coord b, int color)
{
	t_line	line;

	init_line(&line, &a, &b);
	while (line.pt.x <= b.x)
	{
		if (line.steep == 1)
			put_pixel_to_image(img, line.pt.y, line.pt.x, color);
		else
			put_pixel_to_image(img, line.pt.x, line.pt.y, color);
		line.error += line.derror;
		if (line.error > line.dx)
		{
			line.pt.y += (b.y > a.y ? 1 : -1);
			line.error -= line.dx * 2;
		}
		line.pt.x++;
	}
}

t_img	draw(t_mlx *mlx, t_map *map)
{
	t_img	img;
	t_coord	ind;

	(void)map;
	img.ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	img.size_line = mlx->width;
	img.mlx_width = mlx->width;
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.end);
	ind.y = 0;
	while (ind.y < map->lines - 1)
	{
		ind.x = 0;
		while (ind.x < map->columns - 1)
		{
			if (map->print[ind.y][ind.x].x < mlx->width &&
				map->print[ind.y][ind.x + 1].x < mlx->width &&
				map->print[ind.y][ind.x].y < mlx->height &&
				map->print[ind.y][ind.x + 1].y < mlx->height)	
				draw_lines(&img, map->print[ind.y][ind.x], map->print[ind.y][ind.x + 1], 0x008080);
			ind.x++;
		}
		draw_lines(&img, map->print[ind.y][map->columns - 1], map->print[ind.y + 1][map->columns - 1], 0x008080);
		ind.y++;
	}
	ind.x = 0;
	while (ind.x < map->columns	- 1)
	{
		ind.y = 0;
		while (ind.y < map->lines - 1)
		{
			if (map->print[ind.y][ind.x].x < mlx->width &&
				map->print[ind.y + 1][ind.x].x < mlx->width &&
				map->print[ind.y][ind.x].y < mlx->height &&
				map->print[ind.y + 1][ind.x].y < mlx->height)	
				draw_lines(&img, map->print[ind.y][ind.x], map->print[ind.y + 1][ind.x], 0x008080);
			ind.y++;
		}
		draw_lines(&img, map->print[map->lines - 1][ind.x], map->print[map->lines - 1][ind.x + 1], 0x008080);
		ind.x++;
	}
	return (img);
}
