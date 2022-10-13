NAME			=	minishell

CC				=	cc

FLAGS			=	-Wall -Werror -Wextra

RM				=	rm -rf

READLINE_DIR	=	$(shell brew --prefix readline)

READLINE_LIB	=	-lreadline -lhistory -L $(READLINE_DIR)/lib

LIBFT_DIR		=	libft

LIBFT			=	$(LIBFT_DIR)/libft.a

INCLUDES		=	-Iincludes -I$(LIBFT_DIR) -I$(READLINE_DIR)/include

HEADERS			=	includes/minishell.h

SOURCES			=	sources/main.c

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SOURCES) $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SOURCES) $(READLINE_LIB) -o $(NAME)

all: $(NAME)

clean:
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
