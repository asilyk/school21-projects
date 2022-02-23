/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:57:08 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 12:55:47 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map {
	char			**components;
	unsigned int	height;
	unsigned int	width;
	unsigned int	player_position_x;
	unsigned int	player_position_y;
	unsigned int	current_score;
	unsigned int	victory_score;
	unsigned int	number_of_movements;
	void			*floor_image;
	void			*wall_image;
	void			*exit_image;
	void			*collectible_image;
	void			*player_image;
	void			*victory_image;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_vars;

#endif