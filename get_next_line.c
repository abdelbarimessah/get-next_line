/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:04:44 by amessah           #+#    #+#             */
/*   Updated: 2021/11/28 21:46:04 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buffer(int fd, char *str)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*rest(char *s)
{
	char	*nrest;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	len = ft_strlen(&s[i + 1]) + 1;
	nrest = (char *)malloc(sizeof(char) * len);
	if (!nrest)
		return (NULL);
	i++;
	while (s[i])
		nrest[j++] = s[i++];
	nrest[j] = '\0';
	free(s);
	return (nrest);
}

char	*get_next_line(int fd)
{	
	static char	*getbuffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	getbuffer = get_buffer(fd, getbuffer);
	if (!getbuffer)
		return (NULL);
	line = get_line(getbuffer);
	getbuffer = rest(getbuffer);
	return (line);
}
/*
int main()
{
	int fd = open("txt1.txt", O_RDONLY);

	printf("line 1 : %s", get_next_line(fd));
	printf("line 2 : %s", get_next_line(fd));
	printf("line 3 : %s", get_next_line(fd));
	printf("line 4 : %s", get_next_line(fd));
 	printf("line 5 : %s", get_next_line(fd));
}*/