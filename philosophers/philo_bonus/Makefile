CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

NAME			=	philo_bonus

SOURCES			=	main.c \
					ft_check.c \
					ft_parse_argv.c \
					ft_monitor.c \
					ft_philo_actions.c \
					ft_philo_routine.c \
					ft_stop_sim.c \
					ft_utilities.c \

HEADER			=	philo_bonus.h

$(NAME): $(SOURCES) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all
