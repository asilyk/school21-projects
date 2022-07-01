/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:23:20 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 21:22:21 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_mutexes(
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

static int	ft_init_philos(
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
	if (ft_init_mutexes(data->sim_data, data->forks, &data->output) == ERROR
		|| ft_init_philos(data->philos, data->sim_data,
			data->forks, &data->output) == ERROR
		|| ft_create_threads(data->philos_pthreads,
			data->philos, data->sim_data) == ERROR)
	{
		ft_free(data);
		return (ERROR);
	}
	return (OK);
}
