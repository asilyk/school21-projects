/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:13 by fabet             #+#    #+#             */
/*   Updated: 2022/06/28 20:24:15 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(
		pthread_t *philosophers_pthreads,
		t_philosopher *philosophers,
		t_simulation_data *simulation_data)
{
	int	i;

	i = 0;
	while (i < simulation_data->number_of_philosophers)
	{
		if (pthread_create(&philosophers_pthreads[i], NULL, &ft_philosopher_routine, &philosophers[i]) != 0)
		{
			printf("Error! Failed to create thread!\n");
			return (1);
		}
		i++;
	}
	return(0);
}

int	ft_join_threads(pthread_t *philosophers_pthreads, t_simulation_data *simulation_data)
{
	int	i;

	i = 0;
	while (i < simulation_data->number_of_philosophers)
	{
		if (pthread_join(philosophers_pthreads[i], NULL) != 0)
		{
			printf("Error! Failed to join thread!\n");
			return (1);
		}
		i++;
	}
	return(0);
}
