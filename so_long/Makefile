CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
MLX		= -lmlx -lX11 -lXext -lm
HEADER	= so_long.h
NAME	= so_long
SRC		= gnl/get_next_line.c gnl/get_next_line_utils.c \
		  so_long.c create_map.c map_validator.c \
		  control.c hook_init.c rules.c
OBJ		= $(SRC:.c=.o)
LIBFT	= libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(MLX) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
