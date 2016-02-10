/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:05:14 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/10 15:23:33 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned int	win_w;
	unsigned int	win_h;
}					t_mlx;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_map
{
	int				**grid;
	int				height;
	int				width;
}					t_map;

# define COLOR_RED 0xd42121
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLUE 0x5eabcf
# define T_SIZE 32
# define KEY_ESC 53

t_map				parsefile(char *filename);
void				check_values(char *value);

int					handle_keys(int key, void *param);

void				*draw_grid(t_mlx fdf, t_map map);

#endif
