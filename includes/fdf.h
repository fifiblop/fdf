/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:05:14 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/12 18:37:34 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_map
{
	int			columns;
	int			lines;
	int			**parse;
	t_coord		**print;
}				t_map;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
}				t_mlx;

typedef struct	s_img
{
	void		*ptr;
	void		*addr;
	int			bpp;
	int			size_line;
	int			end;
	int			mlx_width;
}				t_img;

typedef struct	s_line
{
	int			steep;
	int			dx;
	int			dy;
	int			error;
	int			derror;
	t_coord		pt;
}				t_line;

/*
** parse.c
*/

t_map			parse(char *filename);
int				get_file_nbline(char *filename);
int				get_file_nbcolumns(char *filename, int line_nb);

/*
** calc.c
*/

void			calc(t_mlx *mlx, t_map *mapi);

/*
** draw.c
*/

void			draw_lines(t_img *img, t_coord a, t_coord b, int color);

/*
** draw.c
*/

t_img			draw(t_mlx *mlx, t_map *map);

/*
** error.c
*/

void			check_lines(char *filename);
void			check_values(char	**tab);

/*
** keys.c
*/

int				key_handler(int key_pressed, void *param);

#endif
