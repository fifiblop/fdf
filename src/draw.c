/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:29:09 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:01 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	img_put_pixel(void *addr, int x, int y, int color, int linesize)
{
	((int*)(addr))[y * linesize + x] = color;
}

void	*draw_grid(t_mlx fdf, t_map map)
{
	int		i;
	int		j;
	void	*img;
	int		endian;
	int		linesize;
	int		bits_per_pixel;
	void	*addr;

	(void)map;
	endian = 0;
	linesize = 100;
	bits_per_pixel = 32;
	img = mlx_new_image(fdf.mlx_ptr, 100, 100);
	addr = mlx_get_data_addr(img, &bits_per_pixel, &linesize, &endian);
	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			img_put_pixel(addr, j, i, COLOR_RED, linesize);
			j++;
		}
		i++;
	}
	return (img);
}
