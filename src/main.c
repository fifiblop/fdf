/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:31:51 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/23 14:07:57 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

t_mlx	init_mlx(int width, int height, char *title, char *file)
{
	t_mlx mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, width, height, title);
	mlx.width = width;
	mlx.height = height;
	mlx.file = file;
	return (mlx);
}

t_src	init_src(t_mlx *mlx, t_map *map, t_img *img, t_mov *mov)
{
	t_src	src;

	src.mlx = mlx;
	src.map = map;
	src.img = img;
	src.mov = mov;
	return (src);
}

t_mov	init_mov(void)
{
	t_mov mov;

	mov.dir.x = 0;
	mov.dir.y = 0;
	mov.haut = 1;
	return (mov);
}

int		main(int ac, char **av)
{
	t_src	src;
	t_mlx	mlx;
	t_map	map;
	t_img	img;
	t_mov	mov;

	if (ac == 2)
	{
		map = parse(av[1]);
		mlx = init_mlx(1000, 1000, "FDF", av[1]);
		mov = init_mov();
		calc(&mlx, &map, &mov);
		img = draw(&mlx, &map);
		src = init_src(&mlx, &map, &img, &mov);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
		mlx_string_put(mlx.ptr, mlx.win, 10, 10, 0xffffff, mlx.file);
		mlx_hook(mlx.win, 2, 0, key_handler, &src);
		mlx_loop(mlx.ptr);
	}
	ft_putnl();
	return (0);
}
