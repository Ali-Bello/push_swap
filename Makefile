NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = algorithm/helpers.c algorithm/main.c algorithm/operations.c algorithm/operations2.c\
	algorithm/parsing.c algorithm/push_to_b.c algorithm/sort.c algorithm/stack.c\

OBJS = $(SRCS:.c=.o)

LIBRARY = mini_libft/libft.a

PROGDIR = algorithm

all: $(LIBRARY) $(NAME)

$(NAME): $(SRCS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Imini_libft -Lmini_libft -lft

$(LIBRARY):
	make -C mini_libft

clean:
	make -C mini_libft clean

fclean: clean
	rm -f $(LIBRARY)
	rm -f $(NAME)

re : fclean all
