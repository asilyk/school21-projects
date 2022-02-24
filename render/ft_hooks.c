/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:21:33 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 14:08:05 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hooks.h"

int	ft_end_game(t_vars *vars)
{
	unsigned int	i;

	i = 0;
	mlx_destroy_window(vars->mlx, vars->win);
	while (vars->map->components[i])
	{
		free(vars->map->components[i]);
		i++;
	}
	free(vars->map->components);
	free(vars->map);
	free(vars);
	exit(0);
	return (0);
}

static void	ft_take_step(t_vars *vars, short int direction, char axis)
{
	if (axis == 'x')
		vars->map->player_position_x += direction;
	if (axis == 'y')
		vars->map->player_position_y += direction;
	if (vars->map->components
		[vars->map->player_position_y][vars->map->player_position_x] == '1')
	{
		if (axis == 'x')
			vars->map->player_position_x -= direction;
		if (axis == 'y')
			vars->map->player_position_y -= direction;
		return ;
	}
	vars->map->number_of_movements++;
}

static void	ft_move_player(t_vars *vars, short int direction, char axis)
{
	ft_take_step(vars, direction, axis);
	if (vars->map->components
		[vars->map->player_position_y][vars->map->player_position_x] == 'C')
	{
		vars->map->components
		[vars->map->player_position_y][vars->map->player_position_x] = '0';
		vars->map->current_score++;
	}
	if (vars->map->components
		[vars->map->player_position_y][vars->map->player_position_x] == 'E')
	{
		if (vars->map->current_score == vars->map->victory_score)
		{
			mlx_clear_window(vars->mlx, vars->win);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->map->victory_image,
				((vars->map->width / 2) - 2) * 50,
				((vars->map->height / 2) - 2) * 50);
			return ;
		}
	}
	mlx_clear_window(vars->mlx, vars->win);
	ft_render_map(vars->mlx, vars->win, vars->map);
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_end_game(vars);
	if (keycode == 13 || keycode == 126)
		ft_move_player(vars, -1, 'y');
	if (keycode == 1 || keycode == 125)
		ft_move_player(vars, 1, 'y');
	if (keycode == 0 || keycode == 123)
		ft_move_player(vars, -1, 'x');
	if (keycode == 2 || keycode == 124)
		ft_move_player(vars, 1, 'x');
	return (0);
}
