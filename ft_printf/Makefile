NAME := libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c functionsone.c functionstwo.c libft/libft.a
LIBFTSRC = libft/
DEPS = ft_printf.h libft/libft.h

#BONUS_SRC 

OBJ = $(SRC:.c=.o)

#BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make all -C ./libft
	$(CC) -o $(NAME) $(OBJ) ./libft/libft.a

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFTSRC)
	rm -f $(OBJ) 

fclean: clean
	make fclean -C $(LIBFTSRC)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
