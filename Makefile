NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  parse_core.c \
		  tool.c \
		  stack.c \
		  ops_basic.c \
		  ops_basic2.c \
		  sort_small.c \
		  arr_utils.c \
		  index_compress.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
