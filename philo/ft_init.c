/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:23:20 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 21:28:19 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sim_data->number_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			ft_print_error("Error! Failed to create mutex!\n");
			return (ERROR);
		}
		i++;
	}
	if (pthread_mutex_init(&data->output, NULL) != 0)
	{
		ft_print_error("Error! Failed to create mutex!\n");
		return (ERROR);
	}
	return (OK);
}

static int	ft_init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sim_data->number_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].sim_data = data->sim_data;
		data->philos[i].last_meal_time = data->sim_data->start_time;
		data->philos[i].output = &data->output;
		data->philos[i].right_fork = &data->forks[i];
		if (i < data->sim_data->number_of_philos - 1)
			data->philos[i].left_fork = &data->forks[i + 1];
		else
			data->philos[i].left_fork = &data->forks[0];
		if (pthread_mutex_init(&data->philos[i].data_mutex, NULL) != 0)
		{
			ft_print_error("Error! Failed to create mutex!\n");
			return (ERROR);
		}
		data->philos[i].meals_count = 0;
		i++;
	}
	return (OK);
}

int	ft_init(int argc, char *argv[], t_data *data)
{
	data->sim_data = ft_parse_argv(argc, argv);
	if (data->sim_data == NULL)
		return (ERROR);
	data->philos_pthreads = (pthread_t *)malloc(sizeof(pthread_t)
			* data->sim_data->number_of_philos);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			*data->sim_data->number_of_philos);
	data->philos = (t_philo *)malloc(sizeof(t_philo)
			* data->sim_data->number_of_philos);
	if (data->philos_pthreads == NULL
		|| data->forks == NULL
		|| data->philos == NULL)
	{
		free(data->sim_data);
		ft_print_error("Error! Failed to allocate memory!\n");
		return (ERROR);
	}
	if (ft_init_mutexes(data) == ERROR
		|| ft_init_philos(data) == ERROR
		|| ft_create_threads(data) == ERROR)
	{
		ft_free(data);
		return (ERROR);
	}
	return (OK);
}
