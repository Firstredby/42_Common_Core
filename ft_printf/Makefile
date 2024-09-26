CC     = cc
AR     = ar rcs
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
NAME   = libftprintf.a
CFILES = ft_printf.c functionsone.c functionstwo.c
OFILES = $(CFILES:.c=.o)
%.o    : %.c
	$(CC) $(CFLAGS) -c $(CFILES)
all: $(NAME)
getlib: 
	make -C ./libft && cp ./libft/libft.a libftprintf.a
$(NAME): getlib $(OFILES) 
	$(AR) $(NAME) $(OFILES) $(HEADER)
clean:
	make clean -C ./libft
	rm -f $(OFILES)
fclean:    clean
	make fclean -C ./libft
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY:  all clean fclean re