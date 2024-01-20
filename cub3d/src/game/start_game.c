/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:22:16 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:22:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "math.h"
#include "raycast.h"
#include "util.h"

void	start_game(t_game *game)
{
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	draw_game(game);
	draw_minimap(game);
}
