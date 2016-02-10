/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:29:09 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/10 19:36:55 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	draw_grid(t_mlx fdf, t_map map)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			x = (j - i) * 32;
			y = (j + i) * 16;
			mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, x + 370, y + 250, COLOR_WHITE);
			j++;
		}
		i++;
	}
}
