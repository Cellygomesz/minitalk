all: client server

server: server.o
	cc -Wall -Wextra -Werror -o server server.o

client: client.o
	cc -Wall -Wextra -Werror -o client client.o

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f client.o server.o

fclean: clean
	rm -f client server

re: fclean all
