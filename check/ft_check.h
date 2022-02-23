/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:12:32 by fabet             #+#    #+#             */
/*   Updated: 2022/02/23 11:09:35 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "so_long.h"

void	ft_check_file(int argc, char *filename);
void	ft_check_map(t_map *map);
void	ft_check_size(t_map *map);
void	ft_check_components(t_map *map);
void	ft_check_walls(t_map *map);
size_t	ft_rowlen(char	*row);

#endif