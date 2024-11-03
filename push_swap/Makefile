CC     = cc
AR     = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
HEADER = push_swap.h
NAME   = push_swap.a
CFILES = push_swap.c DebugPanel.c SortAlg.c \
		 SortSteps1.c SortSteps2.c SortSteps3.c
OFILES = $(CFILES:.c=.o)
%.o    : %.c
	$(CC) $(CFLAGS) -c $(CFILES)
all: $(NAME)
getlib: 
	make -C ./libft && cp ./libft/libft.a push_swap.a
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