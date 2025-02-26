CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = minitalk.h
CCLIENT = client.c
CSERVER = server.c
OCLIENT = $(CCLIENT:.c=.o)
OSERVER = $(CSERVER:.c=.o)
MINILIBFT  = minilibft/minilibft.a

all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OSERVER) $(OCLIENT)
	make -C minilibft
	$(CC) $(CFLAGS) $(OSERVER) $(MINILIBFT) -o $(SERVER)
	$(CC) $(CFLAGS) $(OCLIENT) $(MINILIBFT) -o $(CLIENT)

clean:
	rm -rf $(OCLIENT) $(OSERVER)
	make clean -C ./minilibft/

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	make fclean -C ./minilibft/

re: fclean all

.PHONY: all clean fclean re