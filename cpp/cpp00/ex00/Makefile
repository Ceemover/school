# $< 1st dependency
# $^ all dependencies
# $? all changed dependencies

NAME	= megaphone
SRCS	= megaphone.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror
.PHONY: all re clean clean2 fclean fclean2

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

%.o : %.cpp
	$(CC) -c $^ -o $@

re: fclean all

clean:
	@if [ -f "$(OBJS)" ]; then make --no-print-directory clean2; fi

clean2:
	rm -rf $(OBJS)

fclean: clean
	@if [ -f "$(NAME)" ]; then make --no-print-directory fclean2; fi

fclean2:
	rm -rf $(NAME)
