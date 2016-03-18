/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:01:44 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/18 14:35:49 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

#define KEY_ESC 53
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define KEY_LEFT 123

int		key_handler(int key_pressed, t_src *src)
{
	if (key_pressed == KEY_ESC)
		exit(0);
	if (key_pressed == KEY_UP)
		move_up(src->mlx, src->map, src->img, src->mov);
	if (key_pressed == KEY_DOWN)
		move_down(src->mlx, src->map, src->img, src->mov);
	if (key_pressed == KEY_RIGHT)
		move_right(src->mlx, src->map, src->img, src->mov);
	if (key_pressed == KEY_LEFT)
		move_left(src->mlx, src->map, src->img, src->mov);
	return (0);
}
