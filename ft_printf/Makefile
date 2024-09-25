NAME := libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c functionsone.c functionstwo.c
LIBFTSRC = ../libft/

#BONUS_SRC 

OBJ = $(SRC:.c=.o)

#BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	make -C $(LIBFTSRC)
	cp libft.a
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFTSRC)
	rm -f $(OBJ) 

fclean: clean
	make fclean -C $(LIBFTSRC)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean