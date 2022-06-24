/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:22:14 by fabet             #+#    #+#             */
/*   Updated: 2022/06/24 17:59:07 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexes(t_simulation_data *simulation_data, pthread_mutex_t *forks, pthread_mutex_t *output)
{
	int	i;

	i = 0;
	while (i < simulation_data->number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error! Failed to create mutex!\n");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(output, NULL) != 0)
	{
		printf("Error! Failed to create mutex!\n");
		return (1);
	}
	return (0);
}

int	ft_init_philosophers(t_philosopher *philosophers, t_simulation_data *simulation_data, pthread_mutex_t *forks, pthread_mutex_t *output)
{
	int	i;

	i = 0;
	while (i < simulation_data->number_of_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].simulation_data = simulation_data;
		philosophers[i].last_meal_time = simulation_data->start_time;
		philosophers[i].output = output;
		philosophers[i].right_fork = &forks[i];
		if (i < simulation_data->number_of_philosophers - 1)
			philosophers[i].left_fork = &forks[i + 1];
		else
			philosophers[i].left_fork = &forks[0];
		if (pthread_mutex_init(&philosophers->data_mutex, NULL) != 0)
		{
			printf("Error! Failed to create mutex!\n");
			return (1);
		}
		philosophers[i].meals_count = 0;
		i++;
	}
	return (0);
}
