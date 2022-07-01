/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 12:18:31 by fabet            ###   ########.fr       */
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

	pthread_mutex_init(&global_mutex, NULL);

	philosophers_pthreads = (pthread_t *)malloc(sizeof(pthread_t) * simulation_data->number_of_philosophers);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * simulation_data->number_of_philosophers);
	philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * simulation_data->number_of_philosophers);

	ft_init_mutexes(simulation_data, forks, &output);
	ft_init_philosophers(philosophers, simulation_data, forks, &output);
	ft_create_threads(philosophers_pthreads, philosophers, simulation_data);

	int	i;
	int	fed_philosophers;
	struct timeval	actual_time;
	while(1)
	{
		i = 0;
		fed_philosophers = 0;
		while(i < simulation_data->number_of_philosophers)
		{
			pthread_mutex_lock(&philosophers[i].data_mutex);
			struct timeval last_meal_time = philosophers[i].last_meal_time;
			pthread_mutex_unlock(&philosophers[i].data_mutex);

			gettimeofday(&actual_time, NULL);
			if (ft_count_timestamp_in_ms(last_meal_time, actual_time) > simulation_data->time_to_die)
			{
				pthread_mutex_lock(&simulation_data->sim_data);
				simulation_data->is_stopped = 1;
				pthread_mutex_unlock(&simulation_data->sim_data);

				pthread_mutex_lock(&output);
				printf("%ld %d died\n", ft_count_timestamp_in_ms(simulation_data->start_time, actual_time), philosophers[i].id);
				pthread_mutex_unlock(&output);

				break;
			}

			if (simulation_data->number_of_meals > 0)
			{
				pthread_mutex_lock(&philosophers[i].data_mutex);
				if (philosophers[i].meals_count >= simulation_data->number_of_meals)
					fed_philosophers++;
				pthread_mutex_unlock(&philosophers[i].data_mutex);
			}

			i++;
		}

		if (ft_is_stopped(simulation_data) == 1)
			break;

		if (fed_philosophers == simulation_data->number_of_philosophers)
		{
			pthread_mutex_lock(&simulation_data->sim_data);
			simulation_data->is_stopped = 1;
			pthread_mutex_unlock(&simulation_data->sim_data);
			break;
		}
	}

	ft_join_threads(philosophers_pthreads, simulation_data);

	return (0);
}
