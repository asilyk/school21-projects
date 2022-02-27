/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:04:18 by fabet             #+#    #+#             */
/*   Updated: 2022/02/25 11:09:53 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

size_t	ft_rowlen(char	*row)
{
	size_t	i;

	if (row == NULL)
		return (0);
	i = 0;
	while (row[i] != '\n' && row[i] != '\0')
		i++;
	return (i);
}

static void	ft_check_component(char component, t_vars *vars)
{
	if (component != '0' && component != '1'
		&& component != 'C' && component != 'E'
		&& component != 'P' && component != '\n')
	{
		write(1, "Error! Inknown component in map.\n", 33);
		ft_end_game(vars);
	}
}

void	ft_check_components(t_vars *vars)
{
	size_t	i;
	size_t	j;
	size_t	number_of_exits;

	i = 0;
	number_of_exits = 0;
	while (vars->map->components[i])
	{
		j = 0;
		while (vars->map->components[i][j])
		{
			ft_check_component(vars->map->components[i][j], vars);
			if (vars->map->components[i][j] == 'E')
				number_of_exits++;
			j++;
		}
		i++;
	}
	if (vars->map->victory_score == 0 || vars->map->player_position_x == 0
		|| vars->map->player_position_y == 0 || number_of_exits == 0)
	{
		write(1, "Error! Required map component not found.\n", 41);
		ft_end_game(vars);
	}
}
