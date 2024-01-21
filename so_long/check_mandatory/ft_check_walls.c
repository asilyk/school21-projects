/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:28:28 by fabet             #+#    #+#             */
/*   Updated: 2022/02/26 17:19:29 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

static size_t	ft_is_horizontal_wall(char	*row)
{
	while (*row != '\n' && *row != '\0')
	{
		if (*row != '1')
			return (0);
		row++;
	}
	return (1);
}

static void	ft_check_horizontal_walls(t_vars *vars)
{
	if (ft_is_horizontal_wall(vars->map->components[0]) == 0
		|| ft_is_horizontal_wall(vars->map->components
			[vars->map->height - 1]) == 0)
	{
		write(1, "Error! Map is not surrounded by walls.\n", 39);
		ft_end_game(vars);
	}
}

static void	ft_check_vertical_walls(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (vars->map->components[i])
	{
		if (vars->map->components[i][0] != '1'
		|| vars->map->components[i][vars->map->width - 1] != '1')
		{
			write(1, "Error! Map is not surrounded by walls.\n", 39);
			ft_end_game(vars);
		}
		i++;
	}
}

void	ft_check_walls(t_vars *vars)
{
	ft_check_horizontal_walls(vars);
	ft_check_vertical_walls(vars);
}
