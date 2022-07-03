/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:40:59 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 13:16:27 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define WRONG_FORMAT	-1

# define TRUE			1
# define FALSE			0

# define ERROR			1
# define OK				0

typedef struct timeval	t_timeval;

typedef struct s_sim_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	t_timeval		start_time;
	int				is_stopped;
}	t_sim_data;

// ft_parse_argv.c
t_sim_data	*ft_parse_argv(int argc, char *argv[]);

// ft_utilities.c
int			ft_strict_atoi(const char *str);
void		ft_print_error(char *error_str);

#endif
