/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 15:59:43 by fabet            ###   ########.fr       */
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
	if (sim_data == NULL)
		return (ERROR);
	philos_pthreads = (pthread_t *)malloc(sizeof(pthread_t)
			* sim_data->number_of_philos);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* sim_data->number_of_philos);
	philos = (t_philo *)malloc(sizeof(t_philo) * sim_data->number_of_philos);
	if (philos_pthreads == NULL || forks == NULL || philos == NULL)
	{
		free(sim_data);
		ft_print_error("Error! Failed to allocate memory!\n");
		return (ERROR);
	}
	if (ft_init_mutexes(sim_data, forks, &output) == ERROR
		|| ft_init_philos(philos, sim_data, forks, &output) == ERROR
		|| ft_create_threads(philos_pthreads, philos, sim_data) == ERROR)
	{
		ft_free(sim_data, philos_pthreads, forks, philos);
		return (ERROR);
	}
	ft_monitor(sim_data, philos);
	if (ft_join_threads(philos_pthreads, sim_data) == ERROR)
	{
		ft_free(sim_data, philos_pthreads, forks, philos);
		return (ERROR);
	}
	ft_free(sim_data, philos_pthreads, forks, philos);
	return (OK);
}
