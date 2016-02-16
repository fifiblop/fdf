/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:06:37 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/16 11:52:10 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "mlx.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	t_mlx		fdf;
	t_map		map;
	/*void		*img;*/
	
	t_coord		a;
	t_coord		b;

	if (ac == 2)
	{
		(void)av;
		map = parsefile(av[1]);
		fdf.win_w = 1000;
		fdf.win_h = 1000;
		fdf.mlx_ptr = mlx_init();
		fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.win_w, fdf.win_h, "fdf");
		/*img = draw_grid(fdf, map);*/
		/*mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, img, 0, 0);*/

		a.x = 0;
		a.y = 1000;
		b.x = 1000;
		b.y = 0;
		draw_lines(fdf, a, b, 0xffffff);
		mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 2 ,0, COLOR_WHITE, "ESC TO QUIT");
		mlx_key_hook(fdf.win_ptr, handle_keys, &fdf);
		mlx_loop(fdf.mlx_ptr);
	}
	return (0);
}
