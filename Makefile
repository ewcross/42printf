# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 15:11:23 by ecross            #+#    #+#              #
#    Updated: 2019/12/06 12:22:36 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		list_building_ft_printf.c \
		flag_processing_ft_printf.c \
		output_ft_printf.c \
		new_flag_processing_ft_printf_bonus.c \
		float_ft_printf_bonus.c \
		exponent_ft_printf_bonus.c \
		g_flag_ft_printf_bonus.c \
		wide_processing_ft_printf_bonus.c \
		conv1_ft_printf.c \
		conv2_ft_printf.c \
		conv3_ft_printf_bonus.c \
		utils1_ft_printf.c \
		utils2_ft_printf.c \
		utils3_ft_printf.c \
		utils4_ft_printf.c \
		utils5_ft_printf.c \
		utils6_ft_printf.c \
		utils7_ft_printf.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o: ${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar surc ${NAME} ${OBJS}

all:		${NAME}

bonus:		all

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
