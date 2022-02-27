/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:57:08 by fabet             #+#    #+#             */
/*   Updated: 2022/02/26 17:16:08 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "mlx.h"

# define IMAGES_SCALE 50

typedef size_t	t_direction;
# define LEFT 1
# define RIGHT 0

typedef size_t	t_bool;
# define TRUE 1
# define FALSE 0

typedef void *	t_image;

typedef struct s_map {
	char		**components;
	size_t		height;
	size_t		width;
	size_t		player_position_x;
	size_t		player_position_y;
	size_t		current_score;
	size_t		victory_score;
	size_t		number_of_movements;
	size_t		animation_step;
	t_direction	player_direction;
	size_t		*enemy_positions_x;
	size_t		*enemy_positions_y;
	t_direction	*enemy_directions;
	t_bool		game_is_over;
	t_image		floor_image;
	t_image		wall_image;
	t_image		exit_image;
	t_image		collectible_image1;
	t_image		collectible_image2;
	t_image		collectible_image3;
	t_image		collectible_image4;
	t_image		player_right_image1;
	t_image		player_right_image2;
	t_image		player_left_image1;
	t_image		player_left_image2;
	t_image		victory_image;
	t_image		game_over_image;
	t_image		enemy_right_image1;
	t_image		enemy_right_image2;
	t_image		enemy_left_image1;
	t_image		enemy_left_image2;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_vars;

int	ft_end_game(t_vars *vars);

#endif