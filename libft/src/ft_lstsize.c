/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:39:57 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/09 18:40:07 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_liste_size(t_list *lst)
{
	int		cpt;

	cpt = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		cpt++;
	}
	return (cpt);
}
