# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/07/15 21:18:37 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFTPRINTHPATH = ./lib/printf/
LIBFTPRINTH = ./lib/printf/libftprintf.a

MLX_FLAGS = -lmlx -lXext -lX11
CC = gcc

CFLAG = -Wall -Werror -Wextra -g
INCS = -I ./include/
SRCS = 	./src/so_long.c \
		./src/map_render.c \
		./src/map_load.c \
		./src/map_hooks.c \
		./src/map_check.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPRINTHPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFTPRINTH} $(MLX_FLAGS) 

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
