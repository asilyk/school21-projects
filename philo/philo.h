/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:40 by fabet             #+#    #+#             */
/*   Updated: 2022/06/28 20:24:42 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_simulation_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	struct timeval	start_time;
	int				is_stopped;
}	t_simulation_data;

typedef struct s_philosopher
{
	t_simulation_data	*simulation_data;
	int					id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*output;
	pthread_mutex_t		data_mutex;
	struct timeval		last_meal_time;
	int					meals_count;
}	t_philosopher;

int					ft_strict_atoi(const char *str);
t_simulation_data	*ft_parse_argv(int argc, char *argv[]);

int					ft_init_mutexes(
						t_simulation_data *simulation_data,
						pthread_mutex_t *forks,
						pthread_mutex_t *output);
int					ft_init_philosophers(t_philosopher *philosophers,
						t_simulation_data *simulation_data,
						pthread_mutex_t *forks,
						pthread_mutex_t *output);

int					ft_create_threads(
						pthread_t *philosophers_pthreads,
						t_philosopher *philosophers,
						t_simulation_data *simulation_data);
int					ft_join_threads(
						pthread_t *philosophers_pthreads,
						t_simulation_data *simulation_data);

long				ft_count_timestamp_in_ms(
						struct timeval start_time,
						struct timeval actual_time);

void				ft_sleep(int ms);

void				*ft_philosopher_routine(void *data);

void				ft_free(
						t_simulation_data *simulation_data,
						pthread_t *philosophers_pthreads,
						pthread_mutex_t *forks,
						pthread_mutex_t *output,
						t_philosopher *philosophers);

#endif
