/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:32:21 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/10 14:35:43 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fdf.h>

void	esc_exit(int key)
{
	if (key == KEY_ESC)
		exit(1);
}

int		handle_keys(int key, void *param)
{
	(void)param;
	esc_exit(key);
	return (0);
}
