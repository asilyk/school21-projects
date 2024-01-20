/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:22:11 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:22:12 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <stdlib.h>

int	close_game(t_game *game)
{
	mlx_destroy_window(game->gl.mlx_ptr, game->gl.win_ptr);
	exit(SUCCESS);
}
