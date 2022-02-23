/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:21:09 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 12:39:59 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_MAP_H
# define FT_GET_MAP_H

# include <fcntl.h>
# include "ft_get_next_line.h"
# include "ft_check.h"
# include "so_long.h"

t_map	*ft_get_map(char *filename);

#endif
