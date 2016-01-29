/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:05:08 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/09 20:05:11 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			result;
	int			sign;
	const char	*pos;

	result = 0;
	sign = 0;
	pos = str;
	while (*pos == ' ' || *pos == '\t' || *pos == '\n' || *pos == '\v' ||
			*pos == '\f' || *pos == '\r')
		pos++;
	sign = (*pos == '-') ? -1 : 1;
	pos = (*pos == '-' || *pos == '+') ? pos + 1 : pos;
	while (*pos >= '0' && *pos <= '9')
	{
		result = (result * 10) + (*pos - 48);
		pos++;
	}
	return (result * sign);
}
