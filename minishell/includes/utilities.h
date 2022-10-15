/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:53:41 by fabet             #+#    #+#             */
/*   Updated: 2022/10/15 19:22:05 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "minishell.h"
# include "structures.h"

char	**ft_arrdup(char **arr);
void	ft_free_arr(char **arr);
int		ft_implement_tools(t_tools *tools);
void	ft_init_signals(void);

#endif
