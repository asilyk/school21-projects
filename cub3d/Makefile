# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:02:38 by nkim              #+#    #+#              #
#    Updated: 2022/11/13 18:59:47 by fabet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

LIBFT_DIR	=	./lib/libft

LIBFT_INC	=	-I$(LIBFT_DIR)/libft -I$(LIBFT_DIR)/get_next_line

LIBFT_FLAGS	=	-L./$(LIBFT_DIR) -lft

MLX_DIR		=	./lib/mlx/

MLX_INC		=	-I$(MLX_DIR)

MLX_FLAGS	=	-L./$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

INCS_DIR	=	./include/

INCS		=	-I$(INCS_DIR)

SOURCES		=	src/util/ft_get_line.c \
				src/util/ft_trim_line.c \
				src/util/ft_strtrim_back.c \
				src/util/ft_make_img.c \
				src/util/ft_put_img.c \
				src/util/ft_str_to_rgb.c \
				src/util/ft_get_valid_rgb.c \
				\
				src/parse/parse.c \
				src/parse/parse_map_info.c \
				src/parse/parse_graphic_info.c \
				src/parse/parse_state.c \
				src/parse/valid_extension.c \
				src/parse/valid_map.c \
				src/parse/valid_edge_wall.c \
				src/parse/valid_inner_wall.c \
				\
				src/handler/keypress_handler.c \
				src/handler/check_wall_collision.c \
				\
				src/error/throw_error.c \
				\
				src/draw/draw_minimap.c \
				src/draw/draw_line.c \
				src/draw/draw_square.c \
				src/draw/draw_game.c \
				src/draw/draw_ray.c\
				src/draw/draw_pixel.c \
				src/draw/draw_wall.c \
				\
				src/game/start_game.c \
				src/game/close_game.c \
				\
				src/raycast/raycast.c \
				src/raycast/set_ray.c \
				src/raycast/update_ray.c \
				\
				src/init/init.c \
				src/init/init_state.c \
				src/init/init_info.c \
				\
				src/main/main.c \
				\
				lib/libft/libft/ft_memset.c \
				lib/libft/libft/ft_bzero.c \
				lib/libft/libft/ft_memcpy.c \
				lib/libft/libft/ft_memccpy.c \
				lib/libft/libft/ft_memmove.c \
				lib/libft/libft/ft_memchr.c \
				lib/libft/libft/ft_memcmp.c \
				lib/libft/libft/ft_strlen.c \
				lib/libft/libft/ft_strlcpy.c \
				lib/libft/libft/ft_strlcat.c \
				lib/libft/libft/ft_strchr.c \
				lib/libft/libft/ft_strrchr.c \
				lib/libft/libft/ft_strnstr.c \
				lib/libft/libft/ft_strncmp.c \
				lib/libft/libft/ft_atoi.c \
				lib/libft/libft/ft_isalpha.c \
				lib/libft/libft/ft_isdigit.c \
				lib/libft/libft/ft_isalnum.c \
				lib/libft/libft/ft_isascii.c \
				lib/libft/libft/ft_isprint.c \
				lib/libft/libft/ft_toupper.c \
				lib/libft/libft/ft_tolower.c \
				lib/libft/libft/ft_calloc.c \
				lib/libft/libft/ft_strdup.c \
				lib/libft/libft/ft_substr.c \
				lib/libft/libft/ft_strjoin.c \
				lib/libft/libft/ft_strtrim.c \
				lib/libft/libft/ft_split.c \
				lib/libft/libft/ft_itoa.c \
				lib/libft/libft/ft_strmapi.c \
				lib/libft/libft/ft_putchar_fd.c \
				lib/libft/libft/ft_putstr_fd.c \
				lib/libft/libft/ft_putendl_fd.c \
				lib/libft/libft/ft_putnbr_fd.c \
				lib/libft/libft/ft_lstnew.c \
				lib/libft/libft/ft_lstadd_front.c \
				lib/libft/libft/ft_lstsize.c \
				lib/libft/libft/ft_lstlast.c \
				lib/libft/libft/ft_lstadd_back.c \
				lib/libft/libft/ft_lstdelone.c \
				lib/libft/libft/ft_lstclear.c \
				lib/libft/libft/ft_lstiter.c \
				lib/libft/libft/ft_lstmap.c \
				lib/libft/libft/ft_ptrrealloc.c \
				lib/libft/libft/ft_realloc.c \
				lib/libft/get_next_line/get_next_line.c \
				lib/libft/get_next_line/get_next_line_utils.c

HEADERS		=	include/cub3D.h \
				include/draw.h \
				include/error.h \
				include/game.h \
				include/handler.h \
				include/init.h \
				include/parse.h \
				include/raycast.h \
				include/test.h \
				include/util.h \
				\
				lib/libft/libft/libft.h \
				lib/libft/get_next_line/get_next_line.h

$(NAME): $(SOURCES) $(HEADERS)
	make -s -C $(LIBFT_DIR)
	make -s -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(MLX_INC) $(INCS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(SOURCES) -o $(NAME)

all: $(NAME)

clean:
	make -s -C $(LIBFT_DIR) clean
	make -s -C $(MLX_DIR) clean

fclean: clean
	make -s -C $(LIBFT_DIR) fclean
	make -s -C $(MLX_DIR) clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
