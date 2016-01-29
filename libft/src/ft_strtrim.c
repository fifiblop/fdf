/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:35:05 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/05 10:39:28 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	while (ft_is_blank(*s) && *s++)
		len--;
	ptr = (char*)s;
	while (*ptr)
		ptr++;
	while (ft_is_blank(*(--ptr)) && ptr != s)
		len--;
	if (len <= 0)
		len = 0;
	new = ft_strsub(s, 0, len);
	return (new);
}
