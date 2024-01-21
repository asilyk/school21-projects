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

void	ft_philo_routine(void *args)
{
	t_philo		*philo;
	t_sim_data	*sim_data;

	philo = (t_philo *)args;
	sim_data = philo->sim_data;
	pthread_create(&(philo->death_check), NULL, ft_monitor, args);
	if (philo->id % 2)
		usleep(15000);
	while (!(sim_data->is_stopped))
	{
		ft_take_forks(philo);
		ft_eat(philo);
		if (philo->meals_count >= sim_data->number_of_meals
			&& sim_data->number_of_meals != -1)
			break ;
		ft_fall_asleep(philo);
		ft_think(philo);
	}
	pthread_join(philo->death_check, NULL);
	if (sim_data->is_stopped)
		exit(1);
	exit(0);
}
