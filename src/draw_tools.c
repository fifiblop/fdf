/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:55:43 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/16 14:50:17 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void	put_pixel_to_image(t_img *img, int y, int x, int color)
{
	((int*)(img->addr))[y * img->mlx_width + x] = color;
}

void	init_line(t_line *line, t_coord *a, t_coord *b)
{
	line->steep = 0;
	if (ft_abs(a->x - b->x) < ft_abs(a->y - b->y))
	{
		ft_swap(&a->x, &a->y);
		ft_swap(&b->x, &b->y);
		line->steep = 1;
	}
	if (a->x > b->x)
	{
		ft_swap(&a->x, &b->x);
		ft_swap(&a->y, &b->y);
	}
	line->dx = b->x - a->x;
	line->dy = b->y - a->y;
	line->derror = ft_abs(line->dy) * 2;
	line->error = 0;
	line->pt.x = a->x;
	line->pt.y = a->y;
}

void	draw_lines(t_img *img, t_coord a, t_coord b, int color)
{
	t_line	line;

	init_line(&line, &a, &b);
	while (line.pt.x <= b.x)
	{
		if (line.steep == 1)
			put_pixel_to_image(img, line.pt.x, line.pt.y, color);
		else
			put_pixel_to_image(img, line.pt.y, line.pt.x, color);
		line.error += line.derror;
		if (line.error > line.dx)
		{
			line.pt.y += (b.y > a.y ? 1 : -1);
			line.error -= line.dx * 2;
		}
		line.pt.x++;
	}
}
