# $< 1st dependency
# $^ all dependencies
# $? all changed dependencies

NAME	= replace
SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<  -o $@

re: fclean all

clean:
	@for file in $(OBJS) ; do \
  	(if [ -f $${file} ]; then rm -rf $${file} && echo "rm- rf $${file}"; fi); \
  	done

fclean: clean
	@if [ -f "$(NAME)" ]; then rm -rf $(NAME) && echo "rm- rf $(NAME)"; fi

