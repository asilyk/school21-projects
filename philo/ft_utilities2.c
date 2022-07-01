/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:57:30 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 21:21:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos != NULL)
	{
		while (i < data->sim_data->number_of_philos)
		{
			pthread_mutex_destroy(&data->philos[i].data_mutex);
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->philos);
		pthread_mutex_destroy(&data->output);
	}
	if (data->forks != NULL)
		free(data->forks);
	pthread_mutex_destroy(&data->sim_data->sim_mutex);
	if (data->sim_data != NULL)
		free(data->sim_data);
	if (data->philos_pthreads != NULL)
		free(data->philos_pthreads);
}

void	ft_print(t_philo *philo, char *action_str)
{
	struct timeval	actual_time;
	long			timestamp_in_ms;

	if (ft_is_stopped(philo->sim_data) == FALSE)
	{
		gettimeofday(&actual_time, NULL);
		timestamp_in_ms = ft_count_timestamp_in_ms(philo->sim_data->start_time,
				actual_time);
		pthread_mutex_lock(philo->output);
		printf("%ld %d %s\n", timestamp_in_ms, philo->id, action_str);
		pthread_mutex_unlock(philo->output);
	}
}

void	ft_print_error(char *error_str)
{
	if (error_str != NULL)
	{
		while (*error_str)
		{
			write(2, error_str, 1);
			error_str++;
		}
	}
}
