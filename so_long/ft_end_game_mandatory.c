/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:53:12 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:56:16 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static void	ft_free_components(t_vars *vars)
{
	size_t	i;

	i = 0;
	if (vars->map->components != NULL)
	{
		while (vars->map->components[i])
		{
			free(vars->map->components[i]);
			i++;
		}
		free(vars->map->components);
	}
}

int	ft_end_game(t_vars *vars)
{
	if (vars == NULL)
		exit(1);
	if (vars->mlx != NULL && vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->map == NULL)
		exit(1);
	ft_free_components(vars);
	free(vars->map);
	free(vars);
	exit(1);
	return (0);
}
