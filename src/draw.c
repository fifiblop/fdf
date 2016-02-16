/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:29:09 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/16 11:51:05 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

unsigned long	createRGB(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	put_pixel_to_img(void *addr, int x, int y, int color, int linesize)
{
	((int*)(addr))[y * linesize + x] = color;
}

void	*draw_grid(t_mlx fdf, t_map map)
{
	int		i;
	int		j;
	int		endian;
	int		linesize;
	int		bits_per_pixel;
	void	*addr;
	void	*img;
	t_coord	screen;

	map.tile = 32;
	/*linesize = (map.width * map.tile) * 2;*/
	linesize = fdf.win_w;
	img = mlx_new_image(fdf.mlx_ptr, (map.width * map.tile) * 2, map.height * map.tile);
	img = mlx_new_image(fdf.mlx_ptr, fdf.win_w, fdf.win_h);
	addr = mlx_get_data_addr(img, &bits_per_pixel, &linesize, &endian);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			screen.x = (j - i) * map.tile;
			screen.y = (j + i) * (map.tile/2);
			/*put_pixel_to_img(addr, (j - i) * 32, (j + i) * 16, COLOR_RED, (map.width * map.tile) * 2);*/
			put_pixel_to_img(addr, screen.x + (fdf.win_w/3), screen.y + (fdf.win_h/3), COLOR_WHITE, fdf.win_w);
			j++;
		}
		i++;
	}
	return (img);
}

void	draw_lines(t_mlx fdf, t_coord a, t_coord b, int color)
{
	int	steep;
	int	dx;
	int	dy;
	int	error;
	int	derror;
	int	x;
	int	y;

	steep = 0;
	if (ft_abs(a.x - b.x) < ft_abs(a.y - b.y))
	{
		ft_swap(&a.x, &a.y);
		ft_swap(&b.x, &b.y);
		steep = 1;
	}
	if (a.x > b.x)
	{
		ft_swap(&a.x, &b.x);
		ft_swap(&a.y, &b.y);
	}
	dx = b.x - a.x;
	dy = b.y - a.y;
	derror = ft_abs(dy) * 2;
	error = 0;
	x = a.x;
	y = a.y;
	while (x <= b.x)
	{
		if (steep == 1)
			mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, y, x, color);
		else
			mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, x, y, color);
		error += derror;
		if (error > dx)
		{
			y += (b.y > a.y ? 1 : -1);
			error -= dx * 2;
		}
		x++;
	}
}
