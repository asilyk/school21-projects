/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:24:04 by fabet             #+#    #+#             */
/*   Updated: 2022/06/24 18:53:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(
	t_simulation_data *simulation_data,
	pthread_t *philosophers_pthreads,
	pthread_mutex_t *forks, pthread_mutex_t *output,
	t_philosopher *philosophers)
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
