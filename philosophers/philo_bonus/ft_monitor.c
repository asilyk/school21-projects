/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:43:12 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 13:56:43 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#include "philo_bonus.h"

void	*ft_monitor(void *args)
{
	t_philo		*philo;
	t_timeval	actual_time;

	philo = (t_philo *)args;
	while (TRUE)
	{
		sem_wait(philo->sim_data->data_sem);
		gettimeofday(&actual_time, NULL);
		if (ft_count_timestamp(philo->last_meal_time, actual_time)
			> philo->sim_data->time_to_die)
		{
			ft_print(philo, "died");
			philo->sim_data->is_stopped = 1;
			sem_wait(philo->sim_data->output_sem);
			exit(1);
		}
		sem_post(philo->sim_data->data_sem);
		if (philo->sim_data->is_stopped)
			break ;
		usleep(1000);
		if (philo->meals_count >= philo->sim_data->number_of_meals
			&& philo->sim_data->number_of_meals != -1)
			break ;
	}
	return (NULL);
}
