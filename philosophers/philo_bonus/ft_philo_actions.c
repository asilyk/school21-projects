/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:52:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 14:00:10 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->sim_data->forks_sem);
	ft_print(philo, "has taken a fork");
}

void	ft_take_forks(t_philo *philo)
{
	ft_take_fork(philo);
	ft_take_fork(philo);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->sim_data->data_sem);
	gettimeofday(&philo->last_meal_time, NULL);
	sem_post(philo->sim_data->data_sem);
	ft_print(philo, "is eating");
	ft_sleep(philo->sim_data->time_to_eat);
	sem_post(philo->sim_data->forks_sem);
	sem_post(philo->sim_data->forks_sem);
	sem_wait(philo->sim_data->data_sem);
	philo->meals_count++;
	sem_post(philo->sim_data->data_sem);
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
