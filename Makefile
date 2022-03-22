CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = server client

PRINTF_DIR = ft_printf/

INC = -I $(PRINTF_DIR)includes -I $(PRINTF_DIR)libft

LIBFTPRINTF =  $(PRINTF_DIR)libftprintf.a

SOURCES = server.c client.c

HEADERS = minitalk.h

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) server.c $(INC) $(LIBFTPRINTF) -o server
	$(CC) $(CFLAGS) client.c $(INC) $(LIBFTPRINTF) -o client

clean:
	make clean -C $(PRINTF_DIR)

fclean:
	make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
