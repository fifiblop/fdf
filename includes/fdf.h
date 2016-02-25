/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:05:14 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/25 16:24:39 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>

# define COLOR_RED 0xd42121
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLUE 0x5eabcf
# define T_SIZE 32
# define KEY_ESC 53

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

void			parse(char *filename);

#endif
