/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:22:46 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:22:47 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "init.h"
#include "mlx.h"

void	init(t_game *game)
{
	game->gl.mlx_ptr = mlx_init();
	init_map_info(&game->map_info);
	init_graphic_info(&game->graphic_info, &game->gl);
	init_state(&game->state);
}
