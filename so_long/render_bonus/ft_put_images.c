/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:57:53 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 12:10:37 by fabet            ###   ########.fr       */
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
	t_image	image;

	if (vars->map->components[y / IMAGES_SCALE][x / IMAGES_SCALE] == 'C')
	{
		if (vars->map->animation_step == 1)
			image = vars->map->collectible_image1;
		if (vars->map->animation_step == 2)
			image = vars->map->collectible_image2;
		if (vars->map->animation_step == 3)
			image = vars->map->collectible_image3;
		if (vars->map->animation_step == 4)
			image = vars->map->collectible_image4;
		mlx_put_image_to_window(vars->mlx, vars->win, image, x, y);
	}
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
	t_image	image;

	if (vars->map->animation_step <= 2)
	{
		if (vars->map->player_direction == RIGHT)
			image = vars->map->player_right_image1;
		if (vars->map->player_direction == LEFT)
			image = vars->map->player_left_image1;
	}
	else
	{
		if (vars->map->player_direction == RIGHT)
			image = vars->map->player_right_image2;
		if (vars->map->player_direction == LEFT)
			image = vars->map->player_left_image2;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, image,
		vars->map->player_position_x * IMAGES_SCALE,
		vars->map->player_position_y * IMAGES_SCALE);
}

void	ft_put_enemies_images(t_vars *vars)
{
	size_t	i;
	t_image	enemy_image;

	i = 0;
	while (vars->map->enemy_positions_x[i] != 0)
	{
		if (vars->map->enemy_directions[i] == RIGHT)
		{
			if (vars->map->animation_step == 4)
				enemy_image = vars->map->enemy_right_image2;
			else
				enemy_image = vars->map->enemy_right_image1;
		}
		else
		{
			if (vars->map->animation_step == 4)
				enemy_image = vars->map->enemy_left_image2;
			else
				enemy_image = vars->map->enemy_left_image1;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, enemy_image,
			vars->map->enemy_positions_x[i] * IMAGES_SCALE,
			vars->map->enemy_positions_y[i] * IMAGES_SCALE);
		i++;
	}
}
