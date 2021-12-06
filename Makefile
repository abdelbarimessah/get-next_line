# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amessah <amessah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:54:26 by amessah           #+#    #+#              #
#    Updated: 2021/12/03 14:00:12 by amessah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =   get_next_line.c \
		get_next_line_utils.c \

OBJECTS = $(SRC:.c=.o)

INCLUDES = get_next_line.h \

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	ar rc $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
