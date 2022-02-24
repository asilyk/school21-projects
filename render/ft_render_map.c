/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:20:34 by fabet             #+#    #+#             */
/*   Updated: 2022/02/24 09:42:22 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"
#include "ft_itoa.h"

void	ft_setup_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = 50;
	height = 50;
	map->floor_image = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm",
			&width, &height);
	map->wall_image = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm",
			&width, &height);
	map->exit_image = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm",
			&width, &height);
	map->collectible_image = mlx_xpm_file_to_image(mlx,
			"./textures/collectible.xpm",
			&width, &height);
	map->player_image = mlx_xpm_file_to_image(mlx, "./textures/player.xpm",
			&width, &height);
	width = 250;
	height = 250;
	map->victory_image = mlx_xpm_file_to_image(mlx, "./textures/victory.xpm",
			&width, &height);
}

static void	ft_put_images(void *mlx, void *mlx_win, t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (y < map->height * 50)
	{
		mlx_put_image_to_window(mlx, mlx_win, map->floor_image, x, y);
		if (map->components[y / 50][x / 50] == '1')
			mlx_put_image_to_window(mlx, mlx_win, map->wall_image, x, y);
		if (map->components[y / 50][x / 50] == 'E')
			mlx_put_image_to_window(mlx, mlx_win, map->exit_image, x, y);
		if (map->components[y / 50][x / 50] == 'C')
			mlx_put_image_to_window(mlx, mlx_win, map->collectible_image, x, y);
		x += 50;
		if (x == map->width * 50)
		{
			x = 0;
			y += 50;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, map->player_image,
		map->player_position_x * 50, map->player_position_y * 50);
}

static void	ft_put_strings(void *mlx, void *mlx_win, t_map *map)
{
	mlx_string_put(mlx, mlx_win, 10, 10, 0xFFFFFF, "Number of movements: ");
	mlx_string_put(mlx, mlx_win, 150, 10, 0xFFFFFF,
		ft_itoa(map->number_of_movements));
}

void	ft_render_map(void *mlx, void *mlx_win, t_map *map)
{
	ft_put_images(mlx, mlx_win, map);
	ft_put_strings(mlx, mlx_win, map);
}
