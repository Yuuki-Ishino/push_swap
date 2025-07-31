NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror 

SRC     = push_swap.c parsing.c \
          sort_small.c sort_large.c sort_default.c \
          operations_1.c operations_2.c operations_3.c \
          utils_1.c utils_2.c utils_3.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re