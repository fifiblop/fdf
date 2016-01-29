/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:12:58 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/09 20:13:01 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pback(t_list **alst, void *cnt, size_t cnt_size)
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(cnt, cnt_size);
	}
	else
		*alst = ft_lstnew(cnt, cnt_size);
}
