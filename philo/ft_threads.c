/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:13 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 13:48:25 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(
		pthread_t *philos_pthreads,
		t_philo *philos,
		t_sim_data *sim_data)
{
	int	i;

	i = 0;
	while (i < sim_data->number_of_philos)
	{
		if (pthread_create(&philos_pthreads[i], NULL,
				&ft_philo_routine, &philos[i]) != 0)
		{
			printf("Error! Failed to create thread!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_join_threads(pthread_t *philos_pthreads, t_sim_data *sim_data)
{
	int	i;

	i = 0;
	while (i < sim_data->number_of_philos)
	{
		if (pthread_join(philos_pthreads[i], NULL) != 0)
		{
			printf("Error! Failed to join thread!\n");
			return (1);
		}
		i++;
	}
	return (0);
}
