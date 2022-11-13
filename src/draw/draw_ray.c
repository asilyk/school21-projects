/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:21:51 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:21:52 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "draw.h"
#include "raycast.h"

void	draw_ray(t_game *game, t_ray *ray)
{
	t_point	pos;
	t_point	sp;
	t_point	ep;
	int		b_size;

	b_size = game->minimap_info.b_size;
	pos = game->state.pos;
	sp.x = game->minimap_info.b_size * game->state.pos.x;
	sp.y = game->minimap_info.b_size * game->state.pos.y;
	if (ray->side == X)
	{
		ep.y = b_size * (pos.y + ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (pos.x + ray->perp_wall_dist * ray->ray_dir.x);
	}
	else
	{
		ep.y = b_size * (pos.y + ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (pos.x + ray->perp_wall_dist * ray->ray_dir.x);
	}
	draw_line(&sp, &ep, &game->gl);
}
