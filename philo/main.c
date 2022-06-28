/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexander <alexander@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:34:48 by fabet             #+#    #+#             */
/*   Updated: 2022/06/28 19:38:38 by alexander        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		fed_philosophers = 0;
		while(i < simulation_data->number_of_philosophers)
		{
			printf("WAIT MUTEX OF %d...\n", i);
			pthread_mutex_lock(&philosophers[i].data_mutex);
			printf("GET MUTEX OF %d!\n", i);

			gettimeofday(&actual_time, NULL);
			if (ft_count_timestamp_in_ms(philosophers[i].last_meal_time, actual_time) > simulation_data->time_to_die)
			{
				simulation_data->is_stopped = 1;

				pthread_mutex_lock(&output);
				printf("%ld %d died\n", ft_count_timestamp_in_ms(simulation_data->start_time, actual_time), philosophers[i].id);
				pthread_mutex_lock(&output);

				return (1);
			}
			if (simulation_data->number_of_meals > 0)
			{
				if (philosophers[i].meals_count >= simulation_data->number_of_meals)
					fed_philosophers++;
			}
			i++;

			pthread_mutex_unlock(&philosophers[i].data_mutex);
		}

		if (fed_philosophers == simulation_data->number_of_philosophers)
		{
			pthread_mutex_lock(&philosophers[i].data_mutex);
			simulation_data->is_stopped = 1;
			pthread_mutex_unlock(&philosophers[i].data_mutex);
			break;
		}
	}

	if (ft_join_threads(philosophers_pthreads, simulation_data) != 0)
	{
		//ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);
		return (1);
	}
	//ft_free(simulation_data, philosophers_pthreads, forks, &output, philosophers);

	return (0);
}
