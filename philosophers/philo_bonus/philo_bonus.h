/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:40:59 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 14:13:37 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define TRUE			1
# define FALSE			0

# define ERROR			1
# define OK				0

# define WRONG_FORMAT	-1

typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int					id;
	int					meals_count;
	t_timeval			last_meal_time;
	struct s_sim_data	*sim_data;
	pthread_t			death_check;
	pid_t				pid;
}	t_philo;

typedef struct s_sim_data
{
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	int					is_stopped;
	t_timeval			start_time;
	sem_t				*data_sem;
	sem_t				*forks_sem;
	sem_t				*output_sem;
	t_philo				philos[200];
}	t_sim_data;

// ft_check.c
int		ft_check_argc(int argc);
int		ft_check_sim_data(t_sim_data *sim_data, char **argv);

// ft_parse_argv.c
int		ft_parse_argv(t_sim_data *sim_data, int argc, char **argv);

// ft_monitor.c
void	*ft_monitor(void *args);

// ft_philo_actions.c
void	ft_take_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_fall_asleep(t_philo *philo);
void	ft_think(t_philo *philo);

// ft_philo_routine.c
void	ft_philo_routine(void *args);

// ft_stop_sim.c
void	ft_stop_sim(t_sim_data *sim_data);

// ft_utilities.c
int		ft_strict_atoi(const char *str);
int		ft_count_timestamp(
			t_timeval start_time,
			t_timeval actual_time);
void	ft_sleep(int ms);
void	ft_print(t_philo *philo, char *action_str);
void	ft_print_error(char *error_str);

#endif
