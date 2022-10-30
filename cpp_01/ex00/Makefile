NAME	= zombie

CPP		= g++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

SOURCES	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

HEADERS = Zombie.hpp

$(NAME): $(SOURCES) $(HEADERS)
	$(CPP) $(FLAGS) $(SOURCES) -o $(NAME)

all:	$(NAME)

clean:

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
