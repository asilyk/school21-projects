/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mandatory.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:57:08 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 14:26:19 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MANDATORY_H
# define SO_LONG_MANDATORY_H

# include <stdlib.h>
# include "mlx.h"

# define IMAGES_SCALE 50

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
	t_bool		game_is_over;
	t_image		floor_image;
	t_image		wall_image;
	t_image		exit_image;
	t_image		collectible_image;
	t_image		player_image;
	t_image		victory_image;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_vars;

int	ft_end_game(t_vars *vars);

#endif