CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

NAME			=	philo

SOURCES			=	main.c \
					ft_parse_argv.c \
					ft_init.c \
					ft_monitor.c \
					ft_threads.c \
					ft_philo_actions.c \
					ft_philo_routine.c \
					ft_utilities1.c \
					ft_utilities2.c \

HEADER			=	philo.h

$(NAME): $(SOURCES) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all
