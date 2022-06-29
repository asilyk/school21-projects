/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:38:23 by fabet             #+#    #+#             */
/*   Updated: 2022/06/29 11:05:31 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h> //delete!

static int	ft_check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error! Invalid number of arguments!\n");
		return (1);
	}
	return (0);
}

static t_simulation_data	*ft_init_simulation_data(int argc, char *argv[])
{
	t_simulation_data	*simulation_data;

	simulation_data = (t_simulation_data *)malloc(sizeof(t_simulation_data));
	if (simulation_data == NULL)
	{
		printf("Error! Failed to allocate memory!\n");
		return (NULL);
	}
	if (pthread_mutex_init(&simulation_data->sim_data, NULL) != 0)
	{
		printf("Error! Failed to create mutex!\n");
		return (NULL);
	}
	simulation_data->number_of_philosophers = ft_strict_atoi(argv[1]);
	simulation_data->time_to_die = ft_strict_atoi(argv[2]);
	simulation_data->time_to_eat = ft_strict_atoi(argv[3]);
	simulation_data->time_to_sleep = ft_strict_atoi(argv[4]);
	if (argc == 6)
		simulation_data->number_of_meals = ft_strict_atoi(argv[5]);
	else
		simulation_data->number_of_meals = 0;
	simulation_data->is_stopped = 0;
	return (simulation_data);
}

static int	ft_check_simulation_data(t_simulation_data *simulation_data)
{
	if (simulation_data == NULL)
		return (1);
	if (simulation_data->number_of_philosophers == -1
		|| simulation_data->time_to_die == -1
		|| simulation_data->time_to_eat == -1
		|| simulation_data->time_to_sleep == -1
		|| simulation_data->number_of_meals == -1)
	{
		printf("Error! Invalid arguments format!\n");
		return (1);
	}
	return (0);
}

t_simulation_data	*ft_parse_argv(int argc, char *argv[])
{
	t_simulation_data	*simulation_data;

	if (ft_check_argc(argc) != 0)
		return (NULL);
	simulation_data = ft_init_simulation_data(argc, argv);
	if (ft_check_simulation_data(simulation_data) != 0)
		return (NULL);
	if (gettimeofday(&simulation_data->start_time, NULL) != 0)
	{
		printf("Error! Failed to get time of day!\n");
		return (NULL);
	}
	return (simulation_data);
}
