/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:43:12 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 17:23:27 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_is_dead(t_philo *philo)
{
	t_timeval	actual_time;
	t_timeval	last_meal_time;

	sem_wait(philo->data);
	last_meal_time = philo->last_meal_time;
	sem_post(philo->data);
	gettimeofday(&actual_time, NULL);
	if (ft_count_timestamp(last_meal_time, actual_time)
		> philo->sim_data->time_to_die)
	{
		ft_print(philo, "died");
		sem_wait(philo->data);
		philo->sim_data->is_stopped = TRUE;
		printf("id: %d %p is_stopped=%d\n", philo->id, philo->sim_data, philo->sim_data->is_stopped);
		sem_post(philo->data);
		return (TRUE);
	}
	return (FALSE);
}

void	*ft_monitor(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	while (TRUE)
	{
		if (ft_is_dead(philo) == TRUE)
			return (NULL) ;
	}
	return (NULL);
}
