/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:57:36 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 12:39:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_take_fork(t_philosopher *philosopher, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	ft_print(philosopher, "has taken a fork");
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
	pthread_mutex_lock(&philosopher->data_mutex);
	gettimeofday(&philosopher->last_meal_time, NULL);
	pthread_mutex_unlock(&philosopher->data_mutex);

	ft_print(philosopher, "is eating");

	ft_sleep(philosopher->simulation_data->time_to_eat);

	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);

	pthread_mutex_lock(&philosopher->data_mutex);
	philosopher->meals_count++;
	pthread_mutex_unlock(&philosopher->data_mutex);
}

static void	ft_fall_asleep(t_philosopher *philosopher)
{
	ft_print(philosopher, "is sleeping");
	ft_sleep(philosopher->simulation_data->time_to_sleep);
}

static void ft_think(t_philosopher *philosopher)
{
	ft_print(philosopher, "is thinking");
}

void	*ft_philosopher_routine(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher*)data;
	if (philosopher->id % 2 == 0)
		ft_sleep(philosopher->simulation_data->time_to_eat);
	while (1)
	{
		if (ft_is_stopped(philosopher->simulation_data) == 0)
			ft_take_forks(philosopher);
		else
			break;
		if (ft_is_stopped(philosopher->simulation_data) == 0)
			ft_eat(philosopher);
		else
			break;
		if (ft_is_stopped(philosopher->simulation_data) == 0)
			ft_fall_asleep(philosopher);
		else
			break;
		if (ft_is_stopped(philosopher->simulation_data) == 0)
			ft_think(philosopher);
		else
			break;
	}
	return (NULL);
}
