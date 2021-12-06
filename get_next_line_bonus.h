/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:46:14 by amessah           #+#    #+#             */
/*   Updated: 2021/12/03 13:47:18 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
//# define BUFFER_SIZE 100

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line_bonus(int fd);
char	*rest_bonus(char *str);
char	*get_line_bonus(char *str);
char	*get_buffer_bonus(int fd, char *str);
size_t	ft_strlen_bonus(const	char *s);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*ft_strchr_bonus(const char *s, int c);

#endif