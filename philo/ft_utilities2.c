/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:57:30 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 15:57:58 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_sim_data *sim_data, pthread_t *philos_pthreads, pthread_mutex_t *forks, t_philo *philos)
{
	int	i;


	i = 0;
	if (philos != NULL)
	{
		while (i < sim_data->number_of_philos)
		{
			pthread_mutex_destroy(&philos[i].data_mutex);
			pthread_mutex_destroy(&forks[i]);
			i++;
		}
		free(philos);
		pthread_mutex_destroy(philos[0].output);
	}
	if (forks != NULL)
		free(forks);
	pthread_mutex_destroy(&sim_data->sim_mutex);
	if (sim_data != NULL)
		free(sim_data);
	if (philos_pthreads != NULL)
		free(philos_pthreads);

}

void	ft_print_error(char *error_str)
{
	if (error_str != NULL)
	{
		while (*error_str)
		{
			write(2, error_str, 1);
			error_str++;
		}
	}
}
