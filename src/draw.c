/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:29:09 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/14 19:09:38 by pdelefos         ###   ########.fr       */
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
	endian = 0;
	/*linesize = (map.width * map.tile) * 2;*/
	linesize = fdf.win_w;
	bits_per_pixel = 32;
	/*img = mlx_new_image(fdf.mlx_ptr, (map.width * map.tile) * 2, map.height * map.tile);*/
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
