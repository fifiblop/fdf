/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:28:12 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/18 14:40:21 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#define STEP 5

void	move_up(t_mlx *mlx, t_map *map, t_img *img, t_coord *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->end);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->y -= STEP;
	calc(mlx, map, mov);
	*img = draw(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, mlx->file);
}

void	move_down(t_mlx *mlx, t_map *map, t_img *img, t_coord *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->end);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->y += STEP;
	calc(mlx, map, mov);
	*img = draw(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, mlx->file);
}

void	move_right(t_mlx *mlx, t_map *map, t_img *img, t_coord *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->end);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->x += STEP;
	calc(mlx, map, mov);
	*img = draw(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, mlx->file);
}

void	move_left(t_mlx *mlx, t_map *map, t_img *img, t_coord *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->end);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->x -= STEP;
	calc(mlx, map, mov);
	*img = draw(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, mlx->file);
}
