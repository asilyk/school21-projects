/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:40:59 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 15:46:11 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define WRONG_FORMAT	-1

# define TRUE			1
# define FALSE			0

# define ERROR			1
# define OK				0

# define DEAD			1
# define ALIVE			0

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

typedef struct s_philo
{
	int					id;
	int					meals_count;
	t_timeval			last_meal_time;
	t_sim_data			*sim_data;
}	t_philo;

// ft_parse_argv.c
t_sim_data	*ft_parse_argv(int argc, char *argv[]);

// ft_monitor.c
void	*ft_monitor(void *args);

// ft_philo_actions.c
void		ft_take_forks(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_fall_asleep(t_philo *philo);
void		ft_think(t_philo *philo);

// ft_philo_routine.c
void	ft_philo_routine(t_philo *philo);

// ft_utilities.c
int			ft_strict_atoi(const char *str);
int			ft_count_timestamp(
				t_timeval start_time,
				t_timeval actual_time);
void		ft_sleep(int ms);
int			ft_is_stopped(t_sim_data *sim_data);
void		ft_print(t_philo *philo, char *action_str);
void		ft_print_error(char *error_str);

#endif
