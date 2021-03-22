# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awerebea <awerebea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 14:51:15 by awerebea          #+#    #+#              #
#    Updated: 2020/08/02 06:46:53 by dbolg            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC	= gcc
FLAGS	= -Wall -Wextra -Werror
HEADER	= ft_printf.h
SRC	= ft_printf.c \
	  		libft.c \
			libft2.c \
			process_c_s_x.c \
			process_p_d_i_u.c \
			parse.c 

OBJ      = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

all:			$(NAME)

$(NAME):		$(OBJ)
	ar rcs		$@ $^

$.o: %.c $(HEADER)
##	$(CC)		$(FLAGS) -I Lftprintf -c $< -o $@
	$(CC)		$(FLAGS) -c $< -o $@

clean:
	rm -f		$(OBJ)

fclean:			clean
	rm -f		$(NAME)

re:				fclean $(NAME)
