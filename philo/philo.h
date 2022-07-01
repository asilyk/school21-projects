/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:40 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 15:56:54 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define OK 0

typedef struct s_sim_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	struct timeval	start_time;
	int				is_stopped;
	pthread_mutex_t	sim_mutex;
}	t_sim_data;

typedef struct s_philo
{
	int					id;
	int					meals_count;
	struct timeval		last_meal_time;
	t_sim_data			*sim_data;
	pthread_mutex_t		data_mutex;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*output;
}	t_philo;

int					ft_strict_atoi(const char *str);
void				ft_print(t_philo *philo, char *action_str);
t_sim_data			*ft_parse_argv(int argc, char *argv[]);

int					ft_init_mutexes(
						t_sim_data *sim_data,
						pthread_mutex_t *forks,
						pthread_mutex_t *output);
int					ft_init_philos(t_philo *philos,
						t_sim_data *sim_data,
						pthread_mutex_t *forks,
						pthread_mutex_t *output);

int					ft_create_threads(
						pthread_t *philos_pthreads,
						t_philo *philos,
						t_sim_data *sim_data);
int					ft_join_threads(
						pthread_t *philos_pthreads,
						t_sim_data *sim_data);

long				ft_count_timestamp_in_ms(
						struct timeval start_time,
						struct timeval actual_time);

void				ft_sleep(int ms);

void				*ft_philo_routine(void *data);

void				ft_monitor(t_sim_data *sim_data, t_philo *philos);

int					ft_is_stopped(t_sim_data *sim_data);

void				ft_free(t_sim_data *sim_data,
						pthread_t *philos_pthreads,
						pthread_mutex_t *forks,
						t_philo *philos);

void				ft_print_error(char *error_str);

#endif
