/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:13:46 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 21:31:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_dead(t_sim_data *sim_data, t_philo *philo)
{
	t_timeval	actual_time;
	t_timeval	last_meal_time;

	pthread_mutex_lock(&philo->data_mutex);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->data_mutex);
	gettimeofday(&actual_time, NULL);
	if (ft_count_timestamp_in_ms(last_meal_time, actual_time)
		> sim_data->time_to_die)
	{
		ft_print(philo, "died");
		pthread_mutex_lock(&sim_data->sim_mutex);
		sim_data->is_stopped = TRUE;
		pthread_mutex_unlock(&sim_data->sim_mutex);
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_is_fed(t_sim_data *sim_data, t_philo *philo)
{
	int	is_fed;

	is_fed = FALSE;
	if (sim_data->number_of_meals > 0)
	{
		pthread_mutex_lock(&philo->data_mutex);
		if (philo->meals_count >= sim_data->number_of_meals)
			is_fed = TRUE;
		pthread_mutex_unlock(&philo->data_mutex);
	}
	return (is_fed);
}

static int	ft_are_fed(int fed_philos, t_sim_data *sim_data)
{
	if (fed_philos == sim_data->number_of_philos)
	{
		pthread_mutex_lock(&sim_data->sim_mutex);
		sim_data->is_stopped = TRUE;
		pthread_mutex_unlock(&sim_data->sim_mutex);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_monitor(t_sim_data *sim_data, t_philo *philos)
{
	int	i;
	int	fed_philos;

	while (TRUE)
	{
		i = 0;
		fed_philos = 0;
		while (i < sim_data->number_of_philos)
		{
			if (ft_is_dead(sim_data, &philos[i]) == TRUE)
				return ;
			fed_philos += ft_is_fed(sim_data, &philos[i]);
			i++;
		}
		if (ft_are_fed(fed_philos, sim_data) == TRUE)
			return ;
	}
}
