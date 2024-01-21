/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:25:13 by fabet             #+#    #+#             */
/*   Updated: 2022/02/26 17:57:05 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_map.h"

static size_t	ft_count_enemies(t_vars *vars)
{
	size_t	y;
	size_t	x;
	size_t	enemy_count;

	y = 1;
	x = 1;
	enemy_count = 0;
	while (vars->map->components[y])
	{
		if (vars->map->components[y][y] == '0'
			&& (vars->map->components[y + 1][y]
			|| vars->map->components[y - 1][y]))
			enemy_count++;
		y += 2;
	}
	return (enemy_count);
}

static void	ft_malloc_enemies_data(t_vars *vars)
{
	size_t	enemy_count;

	enemy_count = ft_count_enemies(vars);
	vars->map->enemy_positions_x = (size_t *)malloc(
			sizeof(size_t) * (enemy_count + 1));
	vars->map->enemy_positions_y = (size_t *)malloc(
			sizeof(size_t) * (enemy_count + 1));
	vars->map->enemy_directions = (t_direction *)malloc(
			sizeof(t_direction) * (enemy_count + 1));
	if (vars->map->enemy_positions_x == NULL
		|| vars->map->enemy_positions_y == NULL
		|| vars->map->enemy_directions == NULL)
		ft_end_game(vars);
}

void	ft_create_enemies(t_vars *vars)
{
	size_t	y;
	size_t	x;
	size_t	i;

	ft_malloc_enemies_data(vars);
	y = 1;
	x = 1;
	i = 0;
	while (vars->map->components[y])
	{
		if (vars->map->components[y][y] == '0'
		&& (vars->map->components[y][y + 1] == '0'
		|| vars->map->components[y][y - 1] == '0'))
		{
			vars->map->enemy_positions_x[i] = y;
			vars->map->enemy_positions_y[i] = y;
			vars->map->enemy_directions[i] = RIGHT;
			i++;
		}
		y += 2;
	}
	vars->map->enemy_positions_x[i] = 0;
	vars->map->enemy_positions_y[i] = 0;
}
