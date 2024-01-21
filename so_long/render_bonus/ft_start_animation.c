/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_animation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:04:09 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 12:03:33 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"

static void	ft_bounce_enemy(t_vars *vars, size_t i)
{
	if (vars->map->components
		[vars->map->enemy_positions_y[i]]
		[vars->map->enemy_positions_x[i]] == '1')
	{
		if (vars->map->enemy_directions[i] == RIGHT)
		{
			vars->map->enemy_positions_x[i]--;
			vars->map->enemy_directions[i] = LEFT;
		}
		else
		{
			vars->map->enemy_positions_x[i]++;
			vars->map->enemy_directions[i] = RIGHT;
		}
	}
}

static void	ft_enemy_animation(t_vars *vars)
{
	size_t	i;

	if (vars->map->animation_step == 4)
	{
		i = 0;
		while (vars->map->enemy_positions_x[i] != 0)
		{
			if (vars->map->enemy_directions[i] == RIGHT)
				vars->map->enemy_positions_x[i]++;
			if (vars->map->enemy_directions[i] == LEFT)
				vars->map->enemy_positions_x[i]--;
			ft_bounce_enemy(vars, i);
			i++;
		}
	}
}

static t_bool	ft_show_victory_screen(t_vars *vars)
{
	if (vars->map->components
		[vars->map->player_position_y][vars->map->player_position_x] == 'E')
	{
		if (vars->map->current_score == vars->map->victory_score)
		{
			mlx_clear_window(vars->mlx, vars->win);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->map->victory_image,
				((vars->map->width / 2) - 2) * IMAGES_SCALE,
				((vars->map->height / 2) - 2) * IMAGES_SCALE);
			vars->map->game_is_over = TRUE;
			return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	ft_show_game_over_screen(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (vars->map->enemy_positions_x[i] != 0)
	{
		if (vars->map->player_position_y == vars->map->enemy_positions_y[i]
			&& vars->map->player_position_x == vars->map->enemy_positions_x[i])
		{
			mlx_clear_window(vars->mlx, vars->win);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->map->game_over_image,
				((vars->map->width / 2) - 2) * IMAGES_SCALE,
				((vars->map->height / 2) - 2) * IMAGES_SCALE);
			vars->map->game_is_over = TRUE;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	ft_start_animation(t_vars *vars)
{
	struct timespec	timer;

	timer.tv_sec = 0;
	timer.tv_nsec = 40000000;
	if (vars->map->game_is_over == TRUE)
		return (0);
	vars->map->animation_step++;
	if (vars->map->animation_step > 4)
		vars->map->animation_step = 1;
	ft_enemy_animation(vars);
	nanosleep(&timer, NULL);
	if (ft_show_victory_screen(vars))
		return (0);
	if (ft_show_game_over_screen(vars))
		return (0);
	ft_render_map(vars);
	return (0);
}
