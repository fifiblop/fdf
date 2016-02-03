/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:06:37 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/03 18:14:12 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "mlx.h"
#include "fdf.h"

#define	COLOR_RED 0xd42121
#define COLOR_WHITE 0xFFFFFF
#define COLOR_BLUE 0x5eabcf
#define T_SIZE 32
#define KEY_ESC 53

int		my_func(int key, void *param)
{
	(void)param;
	if (key == KEY_ESC)
		exit(1);
	return (0);
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

void	draw_grid(t_mlx_info fdf, t_grid map)
{
	int		i;
	int		j;
	/*int		x;*/
	/*int		y;*/

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			/*x = (j - i) * 32;*/
			/*ft_putstr("x: ");*/
			/*ft_putnbr(x);*/
			/*y = (j + i) * 16;*/
			/*ft_putstr(" y: ");*/
			/*ft_putnbr(y);*/
			/*ft_putchar('\n');*/
			/*mlx_pixel_put(fdf.mlx, fdf.win, x, y, COLOR_RED);*/
			mlx_pixel_put(fdf.mlx, fdf.win, j * T_SIZE, i * T_SIZE, COLOR_RED);
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_mlx_info	fdf;
	t_grid		map;

	if (ac == 2)
	{
		fdf.win_width = 1000;
		fdf.win_height = 1000;
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, fdf.win_width, fdf.win_height, "fdf");
		map = parsing(av[1]);
		draw_grid(fdf, map);
		mlx_key_hook(fdf.win, my_func, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}
