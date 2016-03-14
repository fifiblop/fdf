/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:01:44 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/12 18:52:03 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#define KEY_ESC 53

int		key_handler(int key_pressed, void *param)
{
	(void)param;
	if (key_pressed == KEY_ESC)
		exit(0);
	return (0);
}
