NAME = so_long.out

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
MLX		=	-L ./mlx -lmlx -framework OpenGL -framework AppKit
INC		=	-I ./mlx -I ./itoa -I ./render -I ./get_next_line -I ./get_map -I ./check -I ./

SRCS	=	get_next_line/ft_get_next_line.c \
			get_next_line/ft_get_next_line_utils.c \
			get_map/ft_get_map.c \
			get_map/ft_create_enemies.c \
			itoa/ft_itoa.c \
			render/ft_key_hook.c \
			render/ft_setup_images.c \
			render/ft_put_images.c \
			render/ft_put_strings.c \
			render/ft_render_map.c \
			render/ft_start_animation.c \
			check/ft_check_file.c \
			check/ft_check_map.c \
			check/ft_check_size.c \
			check/ft_check_components.c \
			check/ft_check_walls.c \
			ft_end_game.c \
			main.c

HEADERS	=	get_next_line/ft_get_next_line.h \
			itoa/ft_itoa.h \
			get_map/ft_get_map.h \
			render/ft_key_hook.h \
			render/ft_render_map.h \
			check/ft_check.h \
			so_long.h

$(NAME): $(SRCS) $(HEADERS)
	make -s -C ./mlx
	$(CC) $(CFLAGS) $(MLX) $(INC) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	make clean -s -C ./mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all