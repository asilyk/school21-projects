/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:04:43 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 12:05:40 by fabet            ###   ########.fr       */
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
	map->game_over_image = mlx_xpm_file_to_image(mlx,
			"./textures/game_over.xpm", &width, &height);
}

static void	ft_setup_collectibles_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = IMAGES_SCALE;
	height = IMAGES_SCALE;
	map->collectible_image1 = mlx_xpm_file_to_image(mlx,
			"./textures/collectible1.xpm",
			&width, &height);
	map->collectible_image2 = mlx_xpm_file_to_image(mlx,
			"./textures/collectible2.xpm",
			&width, &height);
	map->collectible_image3 = mlx_xpm_file_to_image(mlx,
			"./textures/collectible3.xpm",
			&width, &height);
	map->collectible_image4 = mlx_xpm_file_to_image(mlx,
			"./textures/collectible4.xpm",
			&width, &height);
}

static void	ft_setup_player_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = IMAGES_SCALE;
	height = IMAGES_SCALE;
	map->player_right_image1 = mlx_xpm_file_to_image(mlx,
			"./textures/player_right1.xpm", &width, &height);
	map->player_right_image2 = mlx_xpm_file_to_image(mlx,
			"./textures/player_right2.xpm", &width, &height);
	map->player_left_image1 = mlx_xpm_file_to_image(mlx,
			"./textures/player_left1.xpm", &width, &height);
	map->player_left_image2 = mlx_xpm_file_to_image(mlx,
			"./textures/player_left2.xpm", &width, &height);
}

static void	ft_setup_enemies_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = IMAGES_SCALE;
	height = IMAGES_SCALE;
	map->enemy_right_image1 = mlx_xpm_file_to_image(mlx,
			"./textures/enemy_right1.xpm", &width, &height);
	map->enemy_right_image2 = mlx_xpm_file_to_image(mlx,
			"./textures/enemy_right2.xpm", &width, &height);
	map->enemy_left_image1 = mlx_xpm_file_to_image(mlx,
			"./textures/enemy_left1.xpm", &width, &height);
	map->enemy_left_image2 = mlx_xpm_file_to_image(mlx,
			"./textures/enemy_left2.xpm", &width, &height);
}

void	ft_setup_images(t_vars *vars)
{
	ft_setup_environment_images(vars->mlx, vars->map);
	ft_setup_collectibles_images(vars->mlx, vars->map);
	ft_setup_player_images(vars->mlx, vars->map);
	ft_setup_enemies_images(vars->mlx, vars->map);
}
