SERVER 		= server
CLIENT 		= client

CC 		= gcc
RM 		= rm -f
CFLAGS	= -Wall -Wextra -Werror
LIB		=-Llibft -lft

SVR_FILES 	= server.c
CLNT_FILES 	= client.c

INCLUDES = -Ilibft


all: $(SERVER) $(CLIENT) 

$(CLIENT):
	make -C libft
	$(CC) $(LIB) $(INCLUDES) $(CFLAGS) $(CLNT_FILES) -o $@

$(SERVER):
	make -C libft
	$(CC) $(LIB) $(INCLUDES) $(CFLAGS) $(SVR_FILES) -o $@

clean:
	$(RM)
	make clean -C libft

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make fclean -C libft

re: fclean all

.PHONY: all run clean


