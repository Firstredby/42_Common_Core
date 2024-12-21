NAME = ft_printf.a
CC     = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
CFILES = ft_printf.c functionsone.c functionstwo.c ft_putchar_fd.c
OFILES = $(CFILES:.c=.o)
%.o : %.c
	$(CC) $(CFLAGS) -c $(CFILES)
all: $(NAME)
$(NAME): $(OFILES) $(HEADER)
	ar rcs $(NAME) $(OFILES)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re