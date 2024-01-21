NAME	= weapon

CPP		= g++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

SOURCES	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp

$(NAME): $(SOURCES)
	$(CPP) $(FLAGS) $(SOURCES) -o $(NAME)

all:	$(NAME)

clean:

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
