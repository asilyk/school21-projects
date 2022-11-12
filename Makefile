NAME = cub3d

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

MLX				=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

INCLUDES		=	-I ./mlx

SOURCES	=	main.c

HEADERS	=	cub3d.h

$(NAME): $(SOURCES) $(HEADERS)
	make -s -C ./mlx
	$(CC) $(CFLAGS) $(MLX) $(INCLUDES) -o $(NAME) $(SOURCES)

all: $(NAME)

clean:
	make clean -s -C ./mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
