/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexander <alexander@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:57:36 by fabet             #+#    #+#             */
/*   Updated: 2022/06/28 14:29:18 by alexander        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

static void	ft_take_fork(t_philosopher *philosopher, pthread_mutex_t *fork)
{
	struct timeval	actual_time;

	pthread_mutex_lock(fork);
	pthread_mutex_lock(philosopher->output);
	gettimeofday(&actual_time, NULL);
	printf("%ld %d has taken a fork\n", ft_count_timestamp_in_ms(philosopher->simulation_data->start_time, actual_time), philosopher->id);
	pthread_mutex_unlock(philosopher->output);
}

static void	ft_take_forks(t_philosopher *philosopher)
{
	if (philosopher->id != philosopher->simulation_data->number_of_philosophers)
	{
		ft_take_fork(philosopher, philosopher->right_fork);
		ft_take_fork(philosopher, philosopher->left_fork);
	}
	else
	{
		ft_take_fork(philosopher, philosopher->left_fork);
		ft_take_fork(philosopher, philosopher->right_fork);
	}
}

static void	ft_eat(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->output);
	pthread_mutex_lock(&philosopher->data_mutex);
	gettimeofday(&philosopher->last_meal_time, NULL);
	pthread_mutex_unlock(&philosopher->data_mutex);
	printf("%ld %d is eating\n", ft_count_timestamp_in_ms(philosopher->simulation_data->start_time, philosopher->last_meal_time), philosopher->id);
	pthread_mutex_unlock(philosopher->output);
	ft_sleep(philosopher->simulation_data->time_to_eat);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

static void	ft_fall_asleep(t_philosopher *philosopher)
{
	struct timeval	actual_time;

	pthread_mutex_lock(philosopher->output);
	gettimeofday(&actual_time, NULL);
	printf("%ld %d is sleeping\n", ft_count_timestamp_in_ms(philosopher->simulation_data->start_time, actual_time), philosopher->id);
	pthread_mutex_unlock(philosopher->output);
	ft_sleep(philosopher->simulation_data->time_to_sleep);
}

static void ft_think(t_philosopher *philosopher)
{
	struct timeval	actual_time;

	pthread_mutex_lock(philosopher->output);
	gettimeofday(&actual_time, NULL);
	printf("%ld %d is thinking\n", ft_count_timestamp_in_ms(philosopher->simulation_data->start_time, actual_time), philosopher->id);
	pthread_mutex_unlock(philosopher->output);
}

void	*ft_philosopher_routine(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher*)data;

	if (philosopher->id % 2 == 0)
		ft_sleep(philosopher->simulation_data->time_to_eat);
	while (1)
	{
		if (philosopher->simulation_data->is_stopped == 0)
			ft_take_forks(philosopher);
		else
			break;
		if (philosopher->simulation_data->is_stopped == 0)
		{
			ft_eat(philosopher);
			pthread_mutex_lock(&philosopher->data_mutex);
			philosopher->meals_count++;
			pthread_mutex_unlock(&philosopher->data_mutex);
		}
		else
			break;
		if (philosopher->simulation_data->is_stopped == 0)
			ft_fall_asleep(philosopher);
		else
			break;
		if (philosopher->simulation_data->is_stopped == 0)
			ft_think(philosopher);
		else
			break;
		// if (philosopher->simulation_data->is_stopped == 0)
		// 	break;
	}
	return (NULL);
}
