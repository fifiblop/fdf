/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:31:51 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/14 18:00:09 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

t_mlx	init_mlx(int width, int height, char *title)
{
	t_mlx mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, width, height, title);
	mlx.width = width;
	mlx.height = height;
	return (mlx);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;

	if (ac == 2)
	{
		mlx = init_mlx(1000, 1000, av[1]);
		map = parse(av[1]);
		calc(&mlx, &map);
		img = draw(&mlx, &map);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
		mlx_key_hook(mlx.win, key_handler, &mlx);
		mlx_loop(mlx.ptr);
	}
	ft_putnl();
	return (0);
}
