NAME = so_long.out

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
MLX		=	-L ./mlx -lmlx -framework OpenGL -framework AppKit
INC		=	-I ./mlx -I ./render -I ./get_next_line -I ./get_map -I ./check -I ./

SRCS	=	get_next_line/ft_get_next_line.c \
			get_next_line/ft_get_next_line_utils.c \
			get_map/ft_get_map.c \
			render/ft_hooks.c \
			render/ft_render_map.c \
			check/ft_check_file.c \
			check/ft_check_map.c \
			check/ft_check_size.c \
			check/ft_check_components.c \
			check/ft_check_walls.c \
			so_long.c

HEADERS	=	get_next_line/ft_get_next_line.h \
			get_map/ft_get_map.h \
			render/ft_hooks.h \
			render/ft_render_map.h \
			check/ft_check.h

$(NAME): $(SRCS) $(HEADERS)
	make -s -C ./mlx
	$(CC) $(CFLAGS) $(MLX) $(INC) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	make clean -s -C ./mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all