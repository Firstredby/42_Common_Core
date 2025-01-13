NAME	= minilibft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= minilibft.h
CFILES	= ft_printf.c functionsone.c functionstwo.c ft_atoi.c
OFILES	= $(CFILES:.c=.o)

all: $(NAME)
$(NAME): $(OFILES) $(HEADER)
	ar rcs $(NAME) $(OFILES)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re