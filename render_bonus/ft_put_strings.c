/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:03:34 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 12:07:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_map.h"
#include "ft_itoa.h"

void	ft_put_strings(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->map->number_of_movements);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF,
		"Number of movements: ");
	mlx_string_put(vars->mlx, vars->win, 150, 10, 0xFFFFFF, str);
	free(str);
}
