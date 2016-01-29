/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:06:37 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/29 18:02:51 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "fdf.h"

#define KEY_ESC 53

int		my_func(int key, void *param)
{
	(void)param;
	if (key == KEY_ESC)
		exit(1);
	return (0);
}

int		main(void)
{
	t_mlx_info	fdf;
	int		x;
	int		y;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 400, 400, "fdf");
	x = 100;
	while (x < 150)
	{
		y = 100;
		while (y < 150)
		{
			mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0x99FFFF);
			y++;
		}
		x++;
	}
	mlx_key_hook(fdf.win, my_func, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
