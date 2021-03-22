# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 22:33:14 by dbolg             #+#    #+#              #
#    Updated: 2020/12/11 17:00:03 by kcaraway         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = ft_atoi.c ft_strmapi.c ft_bzero.c ft_calloc.c ft_memset.c ft_memcpy.c\
ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c\
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c\
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
get_next_line.c get_next_line_utils.c\
add_str_to_arr.c arr_size.c f_wr_ch.c f_write.c free1.c free2.c free3.c\
ft_free_arr.c ft_strncpy.c

OBJ = $(SRC:.c=.o) 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus my

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo ">ar rcs files added"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean $(NAME)

my: re 
	rm -f $(OBJ)