/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:01:44 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/26 15:16:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define	KEY_ESC 53

int		key_handler(int key_pressed, void *mlx)
{
	(void)mlx;
	if (key_pressed == KEY_ESC)
		exit(0);
	return (0);
}
