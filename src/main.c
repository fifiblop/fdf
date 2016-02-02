/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:06:37 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/02 19:32:07 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "mlx.h"
#include "fdf.h"

#define TILE_SIZE 32
#define KEY_ESC 53
#define	COLOR_RED 0xd42121
#define COLOR_WHITE 0xFFFFFF
#define COLOR_BLUE 0x5eabcf

int		my_func(int key, void *param)
{
	(void)param;
	if (key == KEY_ESC)
		exit(1);
	return (0);
}

void	draw_line(t_mlx_info fdf, t_coord a, t_coord b, int color)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e;
	int		e2;

	dx = b.x - a.x;
	dy = b.y - a.y;
	sx = (a.x < b.x) ? 1 : -1;
	sy = (a.y < b.y) ? 1 : -1;
	e = ((dx > dy) ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break;
		e2 = e;
		if (e2 > -dx)
		{
			e = e - dy;
			a.x = a.x + sx;
		}
		if (e2 < dy)
		{
			e = e + dx;
			a.y = a.y + sy;
		}
	}
}

void	draw_square(t_mlx_info fdf, t_coord a, int width, int color)
{
	int		x;
	int		y;

	y = a.y;
	while (y < (width + a.y))
	{
		x = a.x;
		while (x < (width + a.x))
		{
			mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
			x++;
		}
		y++;
	}
}

/*void	draw_grid(t_coord fdf, int **grid)*/
/*{*/
	/*int		x;*/
	/*int		y;*/
	/*t_coord a;*/
	/*t_coord b;*/

	/*x = 0*/
	/*while (grid[x])*/
	/*{*/
		/*y = 0;*/
		/*while (grid[x][y])*/
		/*{*/
			/*a.x */
			/*draw_line(fdf, )	*/
		/*}*/
	/*}*/

int		main(int ac, char **av)
{
	t_mlx_info	fdf;
	int			**map;
	int			i;
	int			j;

	if (ac == 2)
	{
		fdf.win_width = (TILE_SIZE * 18) + 1;
		fdf.win_height = (TILE_SIZE * 10) + 1;
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, fdf.win_width, fdf.win_height, "fdf");
		map = parsing(av[1]);
		i = 0;
		while (i < 11)
		{
			j = 0;
			while (j < 19)
			{
				mlx_pixel_put(fdf.mlx, fdf.win, j * TILE_SIZE, i * TILE_SIZE, COLOR_RED);
				ft_putnbr(map[i][j]);
				ft_putchar('|');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
		mlx_key_hook(fdf.win, my_func, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}
