# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 03:01:54 by dbolg             #+#    #+#              #
#    Updated: 2020/10/29 11:53:30 by dbolg            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifdef	BONUS_SET
		echo ===COMPILING BONUS===
		HEADER		= cub_bonus.h
		SRCS	= $(shell find bonus -type f -name '*.c')
		OBJS	= $(SRCS:.c=.o)
		FLAG	= ./compile_flags/compile_flag2
		FLAG2	= ./compile_flags/compile_flag
		TEXT	= "bonus ./cub3D compiled"
else
		HEADER		= cub.h
		SRCS	= $(shell find srcs -type f -name '*.c')
		OBJS	= $(SRCS:.c=.o)
		FLAG	= ./compile_flags/compile_flag
		FLAG2	= ./compile_flags/compile_flag2
		TEXT	= "    ./cub3D compiled"
endif

NAME    = cub3D
CC		= gcc
LIBSRCS	= $(shell find libft -type f -name '*.c')
MLXSRCS	= $(shell find linux -type f -name '*.c')
LIBS    = -L./linux -L./libft -lmlx -lXext -lX11 -lm
MLX		= ./linux/libmlx.a
LIBA	= ./libft/libft.a
CFLAGS	= -Wall -Wextra -Werror
FLAG0	= ./compile_flags/compile_flag
FLAG3	= ./compile_flags/compile_flag2

.PHONY: clean fclean all bonus

all: $(NAME) $(TOUCH)
	@touch $(FLAG2)

$(NAME): $(OBJS) $(MLX) $(LIBA) $(FLAG)
	$(CC) $(CFLAGS) ${OBJS} $(MLX) $(LIBA) ${LIBS} -o ${NAME}
	@echo "======================="
	@echo $(TEXT)
	@echo "======================="

$(MLX): $(MLXSRCS)
	$(MAKE) -C linux

$(LIBA): $(LIBSRCS)
	$(MAKE) -C libft

%.o : %.c $(HEADER) 
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(shell find srcs -type f -name '*.o')
	rm -f $(shell find bonus -type f -name '*.o')
	make -C linux/ clean
	make -C libft/ clean
	rm -f save*.bmp
	rm -f ./libft/*.h.gch
	rm -f ./linux/*.gch

fclean: clean
	rm -f $(NAME)
	make -C linux/ fclean
	make -C libft/ fclean

re: fclean all

bonus:
	$(CHECK)
	@$(MAKE) BONUS_SET=1 all
	@touch $(FLAG0)
	
check: $(FLAG3)
	@touch bonus/main.c