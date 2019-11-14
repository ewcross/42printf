# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 15:11:23 by ecross            #+#    #+#              #
#    Updated: 2019/11/14 14:54:08 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		list_building_ft_printf.c \
		flag_processing_ft_printf.c \
		output_ft_printf.c \
		conv1_ft_printf.c \
		conv2_ft_printf.c \
		utils1_ft_printf.c \
		utils2_ft_printf.c \
		utils3_ft_printf.c \
		utils4_ft_printf.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o: ${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar surc ${NAME} ${OBJS}

all:		${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
