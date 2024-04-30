NAME = push_swap

BONUS_NAME = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = algorithm/helpers.c algorithm/main.c algorithm/operations.c\
	algorithm/parsing.c algorithm/push_to_b.c algorithm/sort.c algorithm/stack.c

OBJS = $(SRCS:.c=.o)

LIBRARY = mini_libft/libft.a

BONUS_SRCS = bonus/checker.c bonus/get_next_line.c algorithm/operations.c\
	algorithm/parsing.c algorithm/stack.c algorithm/sort.c algorithm/helpers.c\

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
	rm -f $(BONUS_NAME)

re: fclean all

bonus: $(LIBRARY) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_SRCS) 
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_SRCS) -Imini_libft -Ichecker -Lmini_libft -lft

