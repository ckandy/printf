# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckandy <ckandy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 04:01:35 by ckandy            #+#    #+#              #
#    Updated: 2021/12/15 04:43:54 by ckandy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c
SRCS_B =

HEADER =   ft_printf.h

OBJ = ${patsubst %.c, %.o,${SRCS}}
OBJ_B = ${SRCS_B:%.c=%.o}

CC = gcc
FLAGS = -Wall -Werror -Wextra -I${HEADER}

OPT = -O2

.PHONY : all clean fclean re bonus

all : ${NAME}

${NAME} : ${OBJ} ${HEADER}
	ar rcs ${NAME} $?

%.o : %.c ${HEADER}
	${CC} ${FLAGS} ${OPT} -c $< -o $@

bonus :
	@make OBJ="${OBJ_B}" all

clean :
		@rm -f ${OBJ} ${OBJ_B}

fclean :
		@rm -f ${NAME}

re : 	fclean all
