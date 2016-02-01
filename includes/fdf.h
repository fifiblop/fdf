/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:05:14 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/31 18:33:41 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_mlx_info
{
	void			*mlx;
	void			*win;
	unsigned int	win_width;
	unsigned int	win_height;
}					t_mlx_info;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

void				parsing(char *filename);

#endif
