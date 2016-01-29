/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:01:47 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/04 18:33:40 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (node)
	{
		if (content == NULL)
		{
			node->content = NULL;
			node->content_size = 0;
		}
		else
		{
			node->content = (void*)malloc(content_size);
			if (node->content == NULL)
				return (NULL);
			ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		node->next = NULL;
	}
	return (node);
}
