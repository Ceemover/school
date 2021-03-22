# $< 1st dependency
# $^ all dependencies
# $? all changed dependencies

NAME	= phonebookFrom80s
SRCS	= main.cpp utils.cpp Contacts.cpp
HEADER	= Contacts.hpp
OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror
INCLUDES_DIR = includes

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp $(INCLUDES_DIR)/$(HEADER)
	$(CC) -I./$(INCLUDES_DIR) $(CFLAGS) -c $<  -o $@

re: fclean all

clean:
	@for file in $(OBJS) ; do \
  	(if [ -f $${file} ]; then rm -rf $${file} && echo "rm- rf $${file}"; fi); \
  	done

fclean: clean
	@if [ -f "$(NAME)" ]; then rm -rf $(NAME) && echo "rm- rf $(NAME)"; fi

