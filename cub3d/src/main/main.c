/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:22:51 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:22:52 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "game.h"
#include "handler.h"
#include "init.h"
#include "mlx.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		throw_error("Error: no file argument\n");
	init(&game);
	parse(argv[1], &game);
	start_game(&game);
	mlx_hook(game.gl.win_ptr, KeyPress, 0, &keypress_handler, &game);
	mlx_hook(game.gl.win_ptr, KeyExit, 0, &close_game, &game);
	mlx_loop(game.gl.mlx_ptr);
	return (0);
}
