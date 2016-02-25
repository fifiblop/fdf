/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 18:46:27 by pdelefos          #+#    #+#             */
/*   Updated: 2016/02/17 16:47:34 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_line(char **line, char *stock)
{
	char *nl;

	nl = ft_strchr(stock, '\n');
	if (nl)
	{
		*nl = '\0';
		*line = ft_strdup(stock);
		nl++;
		ft_memmove(stock, nl, ft_strlen(nl) + 1);
		return (1);
	}
	if (ft_strlen(stock) > 0)
	{
		*line = ft_strdup(stock);
		*stock = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*stock = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	long long	ret;

	if (!line || fd < 0)
		return (-1);
	if (stock == NULL)
		stock = ft_strnew(0);
	while (!ft_strchr(stock, '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (ret);
		if (ret == 0)
			return (add_line(line, stock));
		buff[ret] = '\0';
		tmp = ft_strjoin(stock, buff);
		ft_strdel(&stock);
		stock = tmp;
	}
	return (add_line(line, stock));
}
