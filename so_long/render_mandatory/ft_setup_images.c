/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:04:43 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:47:11 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"

static void	ft_setup_environment_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = IMAGES_SCALE;
	height = IMAGES_SCALE;
	map->floor_image = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm",
			&width, &height);
	map->wall_image = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm",
			&width, &height);
	map->exit_image = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm",
			&width, &height);
	width = IMAGES_SCALE * 5;
	height = IMAGES_SCALE * 5;
	map->victory_image = mlx_xpm_file_to_image(mlx,
			"./textures/victory.xpm", &width, &height);
}

static void	ft_setup_collectibles_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = IMAGES_SCALE;
	height = IMAGES_SCALE;
	map->collectible_image = mlx_xpm_file_to_image(mlx,
			"./textures/collectible1.xpm",
			&width, &height);
}

static void	ft_setup_player_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = IMAGES_SCALE;
	height = IMAGES_SCALE;
	map->player_image = mlx_xpm_file_to_image(mlx,
			"./textures/player_right1.xpm", &width, &height);
}

void	ft_setup_images(t_vars *vars)
{
	ft_setup_environment_images(vars->mlx, vars->map);
	ft_setup_collectibles_images(vars->mlx, vars->map);
	ft_setup_player_images(vars->mlx, vars->map);
}
