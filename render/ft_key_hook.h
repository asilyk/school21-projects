/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:54:41 by fabet             #+#    #+#             */
/*   Updated: 2022/02/25 07:54:47 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_KEY_HOOK_H
# define FT_KEY_HOOK_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_render_map.h"

int	ft_key_hook(int keycode, t_vars *vars);

int	ft_end_game(t_vars *vars);

#endif