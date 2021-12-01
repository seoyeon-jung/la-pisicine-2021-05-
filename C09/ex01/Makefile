# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 13:17:34 by seojung           #+#    #+#              #
#    Updated: 2021/09/29 19:41:48 by seojung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c \
	   ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}

HEADERS=includes/ft.h

${NAME}: ${HEADERS} ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}
	
clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
