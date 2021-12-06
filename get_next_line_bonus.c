/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:48 by amessah           #+#    #+#             */
/*   Updated: 2021/12/06 21:18:47 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_buffer_bonus(int fd, char *str)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr_bonus(str, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin_bonus(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_line_bonus(char *s)
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

char	*rest_bonus(char *s)
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
	len = ft_strlen_bonus(&s[i + 1]) + 1;
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

char	*get_next_line_bonus(int fd)
{	
	static char	*getbuffer[6400];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	getbuffer[fd] = get_buffer_bonus(fd, getbuffer[fd]);
	if (!getbuffer[fd])
		return (NULL);
	line = get_line_bonus(getbuffer[fd]);
	getbuffer[fd] = rest_bonus(getbuffer[fd]);
	return (line);
}
// int main()
// {
// 	int fd = open("txt.txt", O_RDONLY);
// 	int fd1 = open("txt1.txt", O_RDONLY);
// 	int fd2 = open("txt2.txt", O_RDONLY);
// 	printf("line 1 : %s", get_next_line_bonus(fd));
// 	printf("line 2 : %s", get_next_line_bonus(fd));
// 	printf("line 1 : %s", get_next_line_bonus(fd1));
// 	printf("line 2 : %s", get_next_line_bonus(fd1));
// 	printf("line 1 : %s", get_next_line_bonus(fd2));
//  printf("line 2 : %s", get_next_line_bonus(fd2));
// }