/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:05:49 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 11:08:28 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

void	ft_check_size(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->components[i])
	{
		if (ft_rowlen(map->components[i]) != map->width)
		{
			write(1, "Error! Map is not rectangular.\n", 31);
			exit(1);
		}
		i++;
	}
}
