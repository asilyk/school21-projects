/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 05:05:35 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 12:03:50 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_hook.h"
#include "ft_get_map.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	ft_check_file(argc, argv[1]);
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		exit (1);
	ft_get_map(*(argv + 1), vars);
	ft_check_map(vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map->width * IMAGES_SCALE,
			vars->map->height * IMAGES_SCALE, "so_long");
	if (vars->map == NULL || vars->mlx == NULL || vars->win == NULL)
		ft_end_game(vars);
	mlx_do_key_autorepeaton(vars->mlx);
	ft_setup_images(vars);
	mlx_key_hook(vars->win, ft_key_hook, vars);
	mlx_loop_hook(vars->mlx, ft_start_animation, vars);
	mlx_hook(vars->win, 17, 0, ft_end_game, vars);
	mlx_loop(vars->mlx);
	return (0);
}
