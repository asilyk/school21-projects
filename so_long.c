/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 05:05:35 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 11:25:22 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hooks.h"
#include "ft_get_map.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	ft_check_file(argc, argv[1]);
	argc = 0;
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		return (1);
	vars->map = ft_get_map(*(argv + 1));
	ft_check_map(vars->map);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map->width * 50,
			vars->map->height * 50, "so_long");
	if (vars->map == NULL || vars->mlx == NULL || vars->win == NULL)
		exit (1);
	ft_setup_images(vars->mlx, vars->map);
	ft_render_map(vars->mlx, vars->win, vars->map);
	mlx_key_hook(vars->win, ft_key_hook, vars);
	mlx_hook(vars->win, 17, 0, ft_end_game, vars);
	mlx_loop(vars->mlx);
	return (0);
}
