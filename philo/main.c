/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:34:48 by fabet             #+#    #+#             */
/*   Updated: 2022/06/13 01:14:53 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

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

int	ft_create_threads(pthread_t *philosophers_pthreads, t_philosopher *philosophers, t_simulation_data *simulation_data)
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

void	ft_free(t_simulation_data *simulation_data, pthread_t *philosophers_pthreads, pthread_mutex_t *forks, pthread_mutex_t *output, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < simulation_data->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&forks[i]) != 0)
		printf("Error! Failed to destroy mutex!\n");
	}
	if (pthread_mutex_destroy(output) != 0)
		printf("Error! Failed to destroy mutex!\n");
	if (forks != NULL)
		free(forks);
	if(philosophers_pthreads != NULL)
		free(philosophers_pthreads);
	if (philosophers != NULL)
		free(philosophers);
	if (simulation_data != NULL)
		free(simulation_data);
}
#include <unistd.h>//
int	main(int argc, char *argv[])
{
	t_simulation_data	*simulation_data;
	pthread_t			*philosophers_pthreads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		output;
	t_philosopher		*philosophers;

	simulation_data = ft_parse_argv(argc, argv);
	if (simulation_data == NULL)
		return (1);

	philosophers_pthreads = (pthread_t *)malloc(sizeof(pthread_t) * simulation_data->number_of_philosophers);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * simulation_data->number_of_philosophers);
	philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * simulation_data->number_of_philosophers);
	if (philosophers_pthreads == NULL || forks == NULL || philosophers == NULL)
	{
		printf("Error! Failed to allocate memory!\n");
		ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);
		return (1);
	}

	if (ft_init_mutexes(simulation_data, forks, &output) != 0)
	{
		ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);
		return (1);
	}

	if (ft_init_philosophers(philosophers, simulation_data, forks, &output) != 0)
	{
		ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);
		return (1);
	}

	if (ft_create_threads(philosophers_pthreads, philosophers, simulation_data) != 0)
	{
		ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);
		return (1);
	}

	int	i;
	int	fed_philosophers;
	struct timeval	actual_time;
	while(1)
	{
		i = 0;
		while(i < simulation_data->number_of_philosophers)
		{
			pthread_mutex_lock(&philosophers[i].data_mutex);
			if (ft_count_timestamp_in_ms(philosophers[i].last_meal_time, actual_time) > simulation_data->time_to_die)
			{
				simulation_data->is_stopped = 1;
				printf("%d %d died\n", ft_count_timestamp_in_ms(simulation_data->start_time, actual_time), philosophers[i].id);
				return (1);
			}
			pthread_mutex_unlock(&philosophers[i].data_mutex);
			if (simulation_data->number_of_meals > 0)
			{
				pthread_mutex_lock(&philosophers[i].data_mutex);
				if (philosophers[i].meals_count >= simulation_data->number_of_meals)
					fed_philosophers++;
				if (gettimeofday(&actual_time, NULL) != 0)
				{
					printf("Error! Failed to get time of day!\n");
					return (1);
				}
				pthread_mutex_unlock(&philosophers[i].data_mutex);
			}
			i++;
		}
		if (fed_philosophers == simulation_data->number_of_philosophers)
		{
			simulation_data->is_stopped = 1;
			break;
		}
		else
			fed_philosophers = 0;
	}

	if (ft_join_threads(philosophers_pthreads, simulation_data) != 0)
	{
		//ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);
		return (1);
	}

	//ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);
	return (0);
}
