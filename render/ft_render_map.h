/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:24:46 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 09:53:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_MAP_H
# define FT_RENDER_MAP_H

# include "mlx.h"
# include "so_long.h"

void	ft_setup_images(void *mlx, t_map *map);
void	ft_render_map(void *mlx, void *mlx_win, t_map *map);

#endif