/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:06:37 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/31 18:33:55 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
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

void	draw_line(t_mlx_info fdf, t_coord a, t_coord b)
{
	float	e;
	short	dx;
	short	dy;
	int		x;
	int		y;

	e = b.x - a.x;
	dx = e * 2;
	dy = (b.y - a.y) * 2;
	x = a.x;
	y = a.y;
	while (x < b.x)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0x00FFFFFF);
		x++;
		if ((e = e - dy) <= 0)
		{
			y++;
			e = e + dx;
		}
	}
	mlx_pixel_put(fdf.mlx, fdf.win, b.x, b.y, 0x00FFFFFF);
}

/*int		main(int ac, char **av)*/
/*{*/
/*if (ac == 2)*/
/*parsing(av[1]);*/
/*return (0);*/
/*}*/

int		main(void)
{
	t_mlx_info	fdf;
	t_coord		a;
	t_coord		b;

	fdf.win_width = 800;
	fdf.win_height = 800;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.win_width, fdf.win_height, "fdf");
	a.x = 10;
	a.y = 10;
	b.x = 200;
	b.y = 10;
	draw_line(fdf, a, b);
	mlx_key_hook(fdf.win, my_func, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
