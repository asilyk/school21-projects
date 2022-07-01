/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 13:13:55 by fabet            ###   ########.fr       */
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
	ft_monitor(simulation_data, philosophers);
	ft_join_threads(philosophers_pthreads, simulation_data);

	return (0);
}
