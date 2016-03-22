/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:07:51 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/22 17:41:37 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_wd(char const *s, char c)
{
	int		i;
	int		size;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	size = ft_strlen(s);
	str = ft_strtrim(s);
	while (i < size)
	{
		if (str[i] != c && str[i + 1] == c)
			count++;
		i++;
	}
	if (str[i] != c)
		count++;
	free(str);
	return (count);
}

static int	ft_len_wd(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		size;

	tab = (char**)ft_memalloc(sizeof(char*) * (ft_count_wd(s, c) + 1));
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size = ft_len_wd(s, c);
			str = ft_strsub(s, 0, size);
			tab[i] = (char*)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
			tab[i] = ft_strcpy(tab[i], str);
			i++;
			free(str);
			s = s + size;
		}
	}
	tab[i] = NULL;
	return (tab);
}
