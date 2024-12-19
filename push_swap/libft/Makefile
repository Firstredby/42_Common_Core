NAME := libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_atoi.c ft_bzero.c  ft_calloc.c ft_itoa.c \
      ft_putstr_fd.c ft_putchar_fd.c ft_split.c ft_strcmp.c \
	  ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c \
	  ft_lstclear_bonus.c ft_strlen.c ft_printf.c functionsone.c \
	  functionstwo.c ft_isdigit.c ft_strdup.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ) libft.h
	ar rcs $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean re fclean