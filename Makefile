SERVER = server
SERVER_SRC = server.c minitalk_utils.c
CLIENT = client
CLIENT_SRC = client.c minitalk_utils.c
INC = minitalk.h
UTILS = minitalk_utils
PRINTF = ft_printf
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: library $(SERVER) $(CLIENT)

library:
	$(MAKE) -C $(PRINTF)

$(SERVER): library 
	cc -g $(SERVER_SRC) $(CFLAGS) -L $(PRINTF) -I ${INC} -o $(SERVER) -lftprintf

$(CLIENT): library
	cc -g $(CLIENT_SRC) $(CFLAGS) -L $(PRINTF) -I ${INC} -o $(CLIENT) -lftprintf

clean:
	$(RM) $(CLIENT) $(SERVER) $(UTILS)
	$(MAKE) clean -C $(PRINTF)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(UTILS)
	$(MAKE) fclean -C $(PRINTF)

re:
	$(MAKE) fclean all

.PHONY: all, clean, re, fclean
