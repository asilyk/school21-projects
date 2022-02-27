/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:05:49 by fabet             #+#    #+#             */
/*   Updated: 2022/02/25 12:43:46 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

void	ft_check_size(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (vars->map->components[i])
	{
		if (ft_rowlen(vars->map->components[i]) != vars->map->width)
		{
			write(1, "Error! Map is not rectangular.\n", 31);
			ft_end_game(vars);
		}
		i++;
	}
}
