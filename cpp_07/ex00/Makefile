NAME	= template

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

SOURCES	= main.cpp

HEADERS =

$(NAME): $(SOURCES) $(HEADERS)
	$(CPP) $(FLAGS) $(SOURCES) -o $(NAME)

all:	$(NAME)

clean:

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
