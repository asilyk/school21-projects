NAME	= weapon

CPP		= g++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

SOURCES	= main.cpp Harl.cpp

HEADERS = Harl.hpp

$(NAME): $(SOURCES)
	$(CPP) $(FLAGS) $(SOURCES) -o $(NAME)

all:	$(NAME)

clean:

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
