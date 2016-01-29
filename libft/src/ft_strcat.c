/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:30:03 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/01 19:23:05 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = (char*)s2;
	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = '\0';
	return (s1);
}
