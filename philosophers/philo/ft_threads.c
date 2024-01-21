/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:13 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 21:29:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sim_data->number_of_philos)
	{
		if (pthread_create(&data->philos_pthreads[i], NULL,
				&ft_philo_routine, &data->philos[i]) != 0)
		{
			ft_print_error("Error! Failed to create thread!\n");
			return (ERROR);
		}
		i++;
	}
	return (OK);
}

int	ft_join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sim_data->number_of_philos)
	{
		if (pthread_join(data->philos_pthreads[i], NULL) != 0)
		{
			ft_print_error("Error! Failed to join thread!\n");
			return (ERROR);
		}
		i++;
	}
	return (OK);
}
