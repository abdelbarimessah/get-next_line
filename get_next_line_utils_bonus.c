/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:44:55 by amessah           #+#    #+#             */
/*   Updated: 2021/12/06 19:59:07 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen_bonus(s1) + ft_strlen_bonus(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen_bonus(const	char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr_bonus(const char *s, int c)
{
	char	c1;
	char	*str;
	int		i;

	c1 = (char )c;
	str = (char *)s;
	i = 0;
	if (c1 == '\0')
		return (str + ft_strlen_bonus(str));
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}
