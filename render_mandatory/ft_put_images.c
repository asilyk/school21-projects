/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:57:53 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 14:24:58 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"

void	ft_put_environment_images(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < vars->map->height * IMAGES_SCALE)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->map->floor_image, x, y);
		if (vars->map->components[y / IMAGES_SCALE]
			[x / IMAGES_SCALE] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->map->wall_image, x, y);
		if (vars->map->components[y / IMAGES_SCALE]
			[x / IMAGES_SCALE] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->map->exit_image, x, y);
		x += IMAGES_SCALE;
		if (x == vars->map->width * IMAGES_SCALE)
		{
			x = 0;
			y += IMAGES_SCALE;
		}
	}
}

static void	ft_put_collectible_image(t_vars *vars, size_t x, size_t y)
{
	if (vars->map->components[y / IMAGES_SCALE][x / IMAGES_SCALE] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->map->collectible_image, x, y);
}

void	ft_put_collectibles_images(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < vars->map->height * IMAGES_SCALE)
	{
		ft_put_collectible_image(vars, x, y);
		x += IMAGES_SCALE;
		if (x == vars->map->width * IMAGES_SCALE)
		{
			x = 0;
			y += IMAGES_SCALE;
		}
	}
}

void	ft_put_player_image(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->map->player_image,
		vars->map->player_position_x * IMAGES_SCALE,
		vars->map->player_position_y * IMAGES_SCALE);
}
