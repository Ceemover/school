# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 07:53:10 by dbolg             #+#    #+#              #
#    Updated: 2020/12/13 07:53:25 by dbolg            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mimishell
CC = gcc
INCLUDES = -I includes/ -I libft/
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
SRCS = ./srcs/
LIB_SRCS = ft_atoi.c ft_strmapi.c ft_bzero.c ft_calloc.c ft_memset.c ft_memcpy.c\
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

BUILTIN = \
builtin/execute_built_in \
builtin/ft_cd \
builtin/ft_echo \
builtin/ft_env \
builtin/ft_export_sort \
builtin/ft_export \
builtin/ft_pwd \
builtin/ft_unset 

EXEC = \
exec/manage_files \
exec/manage_pipe_and_exec \
exec/swap_cmd_name \
exec/swap_cmd_name2

LISTS = \
lists/addback \
lists/new_and_clear

PARSER = \
parser/get_cmd_loop \
parser/get_line_shell \
parser/redir \
parser/skip_dollar \
parser/skip_quotes_slash_space \
parser/validate_line

TOOLS = \
tools/errors \
tools/free_memory \
tools/is_boolean \
tools/strings_arrs \
tools/tools

MAIN = \
main

SRC = $(addprefix $(SRCS), $(addsuffix .c, $(BUILTIN) $(EXEC) $(LISTS) $(PARSER) $(TOOLS) $(MAIN)))
OBJS = $(SRC:.c=.o)

.PHONY: all make_libft make_minishell clean fclean re my

all:
	@$(MAKE) -C libft
	@$(MAKE) make_minishell

make_minishell: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -g -o $(NAME)
	@echo "\033[1;32mmimishell created\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJS)

fclean:
	@make fclean -C libft
	@rm -f $(OBJS)
	@rm -f mimishell
	@echo "\033[1;31mfclean completed\033[0m"

re: fclean all

my: re
	@$(MAKE) clean
