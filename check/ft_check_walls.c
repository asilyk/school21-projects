/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:28:28 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 08:49:08 by fabet            ###   ########.fr       */
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

static void	ft_check_horizontal_walls(t_map *map)
{
	if (ft_is_horizontal_wall(map->components[0]) == 0
		|| ft_is_horizontal_wall(map->components[map->height - 1]) == 0)
	{
		write(1, "Error! Map is not surrounded by walls.\n", 39);
		exit(1);
	}
}

static void	ft_check_vertical_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->components[i])
	{
		if (map->components[i][0] != '1'
		|| map->components[i][map->width - 1] != '1')
		{
			write(1, "Error! Map is not surrounded by walls.\n", 39);
			exit(1);
		}
		i++;
	}
}

void	ft_check_walls(t_map *map)
{
	ft_check_horizontal_walls(map);
	ft_check_vertical_walls(map);
}
