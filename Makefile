# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/07/20 22:48:44 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFTPRINTHPATH = ./lib/printf/
LIBFTPRINTH = ./lib/printf/libftprintf.a

CC = gcc
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include/
SRCS = 	./src/childs.c \
		./src/error.c \
		./src/free.c \
		./src/pipex.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPRINTHPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFTPRINTH}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

clean:
			make clean -C ./lib/printf
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./lib/printf
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
