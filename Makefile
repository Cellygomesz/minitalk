CC= cc
CFLAGS= -Wall -Werror -Wextra


CLIENT= client.c
SERVER= server.c

CLIENT_OBJS= $(CLIENT:.c=.o)
SERVER_OBJS= $(SERVER:.c=.o)

CLIENT_BONUS= client_bonus.c
SERVER_BONUS= server_bonus.c

CLIENT_BONUS_OBJS= $(CLIENT_BONUS:.c=.o)
SERVER_BONUS_OBJS= $(SERVER_BONUS:.c=.o)

all: client server

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o client

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o server

client_bonus: $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) -o client_bonus

server_bonus: $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) -o server_bonus


bonus: client_bonus server_bonus

fclean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
	rm -f client server client_bonus server_bonus

re: fclean all

