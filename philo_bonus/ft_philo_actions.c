/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:52:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 15:29:22 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_take_fork(t_philo *philo)
{
	// pthread_mutex_lock(fork);
	ft_print(philo, "has taken a fork");
}

void	ft_take_forks(t_philo *philo)
{
	if (philo->id != philo->sim_data->number_of_philos)
	{
		ft_take_fork(philo);
		ft_take_fork(philo);
	}
	else
	{
		ft_take_fork(philo);
		if (philo->sim_data->number_of_philos > 1)
			ft_take_fork(philo);
	}
}

void	ft_eat(t_philo *philo)
{
	// pthread_mutex_lock(&philo->data_mutex);
	gettimeofday(&philo->last_meal_time, NULL);
	// pthread_mutex_unlock(&philo->data_mutex);
	ft_print(philo, "is eating");
	ft_sleep(philo->sim_data->time_to_eat);
	// pthread_mutex_unlock(philo->right_fork);
	// pthread_mutex_unlock(philo->left_fork);
	// pthread_mutex_lock(&philo->data_mutex);
	philo->meals_count++;
	// pthread_mutex_unlock(&philo->data_mutex);
}

void	ft_fall_asleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_sleep(philo->sim_data->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking");
}
