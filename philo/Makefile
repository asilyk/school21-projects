CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

NAME			=	philo

SOURCES			=	*.c

HEADER			=	*.h

$(NAME): $(SOURCES) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all
