/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:23:20 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 15:38:18 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexes(
			t_sim_data *sim_data,
			pthread_mutex_t *forks,
			pthread_mutex_t *output)
{
	int	i;

	i = 0;
	while (i < sim_data->number_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			ft_print_error("Error! Failed to create mutex!\n");
			return (ERROR);
		}
		i++;
	}
	if (pthread_mutex_init(output, NULL) != 0)
	{
		ft_print_error("Error! Failed to create mutex!\n");
		return (ERROR);
	}
	return (OK);
}

int	ft_init_philos(
			t_philo *philos,
			t_sim_data *sim_data,
			pthread_mutex_t *forks,
			pthread_mutex_t *output)
{
	int	i;

	i = 0;
	while (i < sim_data->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].sim_data = sim_data;
		philos[i].last_meal_time = sim_data->start_time;
		philos[i].output = output;
		philos[i].right_fork = &forks[i];
		if (i < sim_data->number_of_philos - 1)
			philos[i].left_fork = &forks[i + 1];
		else
			philos[i].left_fork = &forks[0];
		if (pthread_mutex_init(&philos[i].data_mutex, NULL) != 0)
		{
			ft_print_error("Error! Failed to create mutex!\n");
			return (ERROR);
		}
		philos[i].meals_count = 0;
		i++;
	}
	return (OK);
}
