/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:24:46 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:55:14 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_MAP_H
# define FT_RENDER_MAP_H

# include <time.h>
# include "mlx.h"
# include "so_long_mandatory.h"

void	ft_setup_images(t_vars *vars);
void	ft_put_environment_images(t_vars *vars);
void	ft_put_collectibles_images(t_vars *vars);
void	ft_put_player_image(t_vars *vars);
void	ft_render_map(t_vars *vars);
int		ft_start_animation(t_vars *vars);

#endif