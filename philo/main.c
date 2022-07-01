/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 13:50:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_sim_data			*sim_data;
	pthread_t			*philos_pthreads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		output;
	t_philo				*philos;

	sim_data = ft_parse_argv(argc, argv);
	philos_pthreads = (pthread_t *)malloc(sizeof(pthread_t) * sim_data->number_of_philos);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * sim_data->number_of_philos);
	philos = (t_philo *)malloc(sizeof(t_philo) * sim_data->number_of_philos);
	ft_init_mutexes(sim_data, forks, &output);
	ft_init_philos(philos, sim_data, forks, &output);
	ft_create_threads(philos_pthreads, philos, sim_data);
	ft_monitor(sim_data, philos);
	ft_join_threads(philos_pthreads, sim_data);

	return (0);
}
