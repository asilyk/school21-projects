NAME	= animal

CPP		= g++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

SOURCES	= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp

$(NAME): $(SOURCES) $(HEADERS)
	$(CPP) $(FLAGS) $(SOURCES) -o $(NAME)

all:	$(NAME)

clean:

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
