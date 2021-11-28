/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:04:46 by amessah           #+#    #+#             */
/*   Updated: 2021/11/28 21:24:50 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
//# define BUFFER_SIZE 100

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int	fd);
char	*rest(char *str);
char	*get_line(char *str);
char	*get_buffer(int fd,char *str);
size_t	ft_strlen(const	char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);


#endif