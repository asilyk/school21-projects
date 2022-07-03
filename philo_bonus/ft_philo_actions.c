/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:52:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 16:56:49 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->sim_data->forks);
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
	sem_wait(philo->data);
	gettimeofday(&philo->last_meal_time, NULL);
	sem_post(philo->data);
	ft_print(philo, "is eating");
	ft_sleep(philo->sim_data->time_to_eat);
	sem_post(philo->sim_data->forks);
	sem_post(philo->sim_data->forks);
	sem_wait(philo->data);
	philo->meals_count++;
	sem_post(philo->data);
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
