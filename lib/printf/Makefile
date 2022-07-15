# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 19:09:53 by aminoru-          #+#    #+#              #
#    Updated: 2022/07/07 17:56:10 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFT = ../libft/libft.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
INCS	= -I ../libft
PRINTH  = ft_printf.h
SRCS	=	ft_appendchr.c \
			ft_convertions_utils.c \
			ft_convert_s.c \
			ft_fs_sub_specifier.c \
			ft_printf.c \
			ft_uitoa.c \
			ft_convert_c.c \
			ft_convert_p.c \
			ft_convert_ux.c \
			ft_inicialize.c \
			ft_strndup.c \
			ft_convert_d_i.c \
			ft_convert_pct.c \
			ft_format_specifiers.c \
			ft_placeholder.c \
			ft_type_specifier.c

OBJS	=	${SRCS:.c=.o}

all: 		${NAME}

${NAME}: 	${OBJS} $(LIBFT) $(PRINTH)
				ar -rcs ${NAME} ${OBJS}
				ranlib ${NAME}

bonus:	all 

.c.o:
				${CC} ${CFLAGS} $(INCS) -c $< -o ${<:.c=.o}

$(LIBFT):
				make -C ../libft
				cp $(LIBFT) $(NAME)

clean:
				make clean -C ../libft
				rm -f ${OBJS} ${OBJS_BONUS}

fclean: 	clean
				make fclean -C ../libft
				rm -f ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY: all clean fclean re bonus rebonus