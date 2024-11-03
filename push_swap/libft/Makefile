NAME := libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ) libft.h
	ar rcs $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean re fclean 