/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:12:32 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:55:06 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include <unistd.h>
# include <fcntl.h>
# include "so_long_mandatory.h"

void	ft_check_file(int argc, char *filename);
void	ft_check_map(t_vars *vars);
void	ft_check_size(t_vars *vars);
void	ft_check_components(t_vars *vars);
void	ft_check_walls(t_vars *vars);
size_t	ft_rowlen(char	*row);

#endif