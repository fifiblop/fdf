/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:29:09 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/10 15:23:37 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	*draw_grid(t_mlx fdf, t_map map)
{
	int		i;
	int		j;
	int		x;
	int		y;
	void	*img;

	i = 0;
	img = mlx_new_image(fdf.mlx_ptr, fdf.win_w, fdf.win_h);
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
	return (img);
}
