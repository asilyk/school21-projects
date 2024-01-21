/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:21:33 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:53:41 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_hook.h"

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
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_end_game(vars);
	if (vars->map->game_is_over == FALSE)
	{
		if (keycode == 13 || keycode == 126)
			ft_move_player(vars, -1, 'y');
		if (keycode == 1 || keycode == 125)
			ft_move_player(vars, 1, 'y');
		if (keycode == 0 || keycode == 123)
			ft_move_player(vars, -1, 'x');
		if (keycode == 2 || keycode == 124)
			ft_move_player(vars, 1, 'x');
	}
	return (0);
}
