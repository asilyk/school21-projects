/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:20:34 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 12:02:39 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"
#include "so_long.h"

void	ft_render_map(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	ft_put_environment_images(vars);
	ft_put_collectibles_images(vars);
	ft_put_player_image(vars);
	ft_put_enemies_images(vars);
	ft_put_strings(vars);
}
