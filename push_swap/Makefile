CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
HEADER = push_swap.h
NAME   = push_swap
CFILES = push_swap.c DebugPanel.c Stacksort.c \
         SortSteps1.c SortSteps2.c Quicksort.c \
		 Stacksort_utils.c input_validation.c
OFILES = $(CFILES:.c=.o)
LIBFT  = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	make -C libft
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -lm -o $(NAME)
	chmod +x $(NAME)

clean:
	make clean -C libft
	rm -f $(OFILES)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re