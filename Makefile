NAME = so_long.out

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
MLX				=	-L ./mlx -lmlx -framework OpenGL -framework AppKit
INC_MANDATORY	=	-I ./mlx -I ./render_mandatory -I ./get_next_line -I ./get_map_mandatory -I ./check_mandatory -I ./

SRCS_MANDATORY	=	get_next_line/ft_get_next_line.c \
					get_next_line/ft_get_next_line_utils.c \
					get_map_mandatory/ft_get_map.c \
					render_mandatory/ft_key_hook.c \
					render_mandatory/ft_setup_images.c \
					render_mandatory/ft_put_images.c \
					render_mandatory/ft_render_map.c \
					render_mandatory/ft_start_animation.c \
					check_mandatory/ft_check_file.c \
					check_mandatory/ft_check_map.c \
					check_mandatory/ft_check_size.c \
					check_mandatory/ft_check_components.c \
					check_mandatory/ft_check_walls.c \
					ft_end_game_mandatory.c \
					main.c

HEADERS_MANDATORY	=	get_next_line/ft_get_next_line.h \
						get_map_mandatory/ft_get_map.h \
						render_mandatory/ft_key_hook.h \
						render_mandatory/ft_render_map.h \
						check_mandatory/ft_check.h \
						so_long_mandatory.h

$(NAME): $(SRCS_MANDATORY) $(HEADERS_MANDATORY)
	make -s -C ./mlx
	$(CC) $(CFLAGS) $(MLX) $(INC_MANDATORY) -o $(NAME) $(SRCS_MANDATORY)

all: $(NAME)

clean:
	make clean -s -C ./mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all