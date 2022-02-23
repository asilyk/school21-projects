/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:24:50 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 09:53:39 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HOOKS_H
# define FT_HOOKS_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_render_map.h"

int	ft_key_hook(int keycode, t_vars *vars);

int	ft_end_game(t_vars *vars);

#endif