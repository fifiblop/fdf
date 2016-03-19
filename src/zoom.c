/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:22:59 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/19 16:24:53 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

void	zoom_up(t_mlx *mlx, t_map *map, t_img *img, t_mov *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->end);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->haut += 1;
	calc(mlx, map, mov);
	*img = draw(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, mlx->file);
}

void	zoom_down(t_mlx *mlx, t_map *map, t_img *img, t_mov *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->end);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->haut -= 1;
	calc(mlx, map, mov);
	*img = draw(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, mlx->file);
}
