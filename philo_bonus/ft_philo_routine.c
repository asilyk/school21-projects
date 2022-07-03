/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:57:36 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 13:23:41 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_routine_cycle(t_philo *philo)
{
	if (ft_is_stopped(philo->sim_data) == FALSE)
		ft_take_forks(philo);
	else
		return (DEAD);
	if (ft_is_stopped(philo->sim_data) == FALSE
		&& philo->sim_data->number_of_philos > 1)
		ft_eat(philo);
	else
		return (DEAD);
	if (ft_is_stopped(philo->sim_data) == FALSE)
		ft_fall_asleep(philo);
	else
		return (DEAD);
	if (ft_is_stopped(philo->sim_data) == FALSE)
		ft_think(philo);
	else
		return (DEAD);
	return (ALIVE);
}

void	ft_philo_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	if (philo->id % 2 == 0)
		ft_sleep(philo->sim_data->time_to_eat);
	if (pthread_create(&monitor_thread, NULL,
			&ft_monitor, philo) != 0)
	{
		ft_print_error("Error! Failed to create thread!\n");
		return ;
	}
	while (TRUE)
	{
		if (ft_routine_cycle(philo) == DEAD)
			break ;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		ft_print_error("Error! Failed to join thread!\n");
	return ;
}
