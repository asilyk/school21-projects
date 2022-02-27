NAME = so_long.out

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
MLX				=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

INC_MANDATORY	=	-I ./mlx -I ./render_mandatory -I ./get_next_line -I ./get_map_mandatory -I ./check_mandatory -I ./
INC_BONUS		=	-I ./mlx -I ./itoa -I ./render_bonus -I ./get_next_line -I ./get_map_bonus -I ./check_bonus -I ./

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

SRCS_BONUS	=	get_next_line/ft_get_next_line.c \
				get_next_line/ft_get_next_line_utils.c \
				get_map_bonus/ft_get_map.c \
				get_map_bonus/ft_create_enemies.c \
				itoa/ft_itoa.c \
				render_bonus/ft_key_hook.c \
				render_bonus/ft_setup_images.c \
				render_bonus/ft_put_images.c \
				render_bonus/ft_put_strings.c \
				render_bonus/ft_render_map.c \
				render_bonus/ft_start_animation.c \
				check_bonus/ft_check_file.c \
				check_bonus/ft_check_map.c \
				check_bonus/ft_check_size.c \
				check_bonus/ft_check_components.c \
				check_bonus/ft_check_walls.c \
				ft_end_game_bonus.c \
				main.c

HEADERS_BONUS	=	get_next_line/ft_get_next_line.h \
					itoa/ft_itoa.h \
					get_map_bonus/ft_get_map.h \
					render_bonus/ft_key_hook.h \
					render_bonus/ft_render_map.h \
					check_bonus/ft_check.h \
					so_long_bonus.h

$(NAME): $(SRCS_MANDATORY) $(HEADERS_MANDATORY)
	make -s -C ./mlx
	$(CC) $(CFLAGS) $(MLX) $(INC_MANDATORY) -o $(NAME) $(SRCS_MANDATORY)

bonus: $(SRCS_BONUS) $(HEADERS_BONUS)
	make -s -C ./mlx
	$(CC) $(CFLAGS) $(MLX) $(INC_BONUS) -o $(NAME) $(SRCS_BONUS)

all: $(NAME)

clean:
	make clean -s -C ./mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all