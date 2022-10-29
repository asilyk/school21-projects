NAME	= weapon

CPP		= g++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

SOURCES	= main.cpp Weapon.hpp Weapon.cpp HumanA.hpp HumanA.cpp HumanB.hpp HumanB.cpp

$(NAME): $(SOURCES)
	$(CPP) $(FLAGS) $(SOURCES) -o $(NAME)

all:	$(NAME)

clean:

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
