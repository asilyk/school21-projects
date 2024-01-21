/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_animation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:04:09 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:43:10 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"

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

int	ft_start_animation(t_vars *vars)
{
	struct timespec	timer;

	timer.tv_sec = 0;
	timer.tv_nsec = 40000000;
	if (vars->map->game_is_over == TRUE)
		return (0);
	nanosleep(&timer, NULL);
	if (ft_show_victory_screen(vars))
		return (0);
	ft_render_map(vars);
	return (0);
}
