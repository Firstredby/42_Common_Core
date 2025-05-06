NAME    = philo
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3
PTHREAD = -lpthread
SRC     = src/philo.c src/philo_utils.c src/error_cases.c \
		  src/main_process.c src/init.c
OBJ_DIR = obj
OBJ     = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(PTHREAD) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

