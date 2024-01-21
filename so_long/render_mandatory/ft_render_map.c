/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:20:34 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:55:34 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"
#include "so_long_mandatory.h"

void	ft_render_map(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	ft_put_environment_images(vars);
	ft_put_collectibles_images(vars);
	ft_put_player_image(vars);
}
