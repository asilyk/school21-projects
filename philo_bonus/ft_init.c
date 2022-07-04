/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:51:17 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 23:16:39 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*ft_init_philos(t_sim_data *sim_data)
{
	t_philo		*philos;
	int			i;

	philos = (t_philo *)malloc(sizeof(t_philo) * sim_data->number_of_philos);
	if (philos == NULL)
	{
		ft_print_error("Error! Failed to allocate memory!\n");
		return (NULL);
	}
	i = 0;
	while (i < sim_data->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].sim_data = sim_data;
		philos[i].last_meal_time = sim_data->start_time;
		philos[i].meals_count = 0;
		sem_unlink(DATA_SEM);
		philos[i].data = sem_open(DATA_SEM, O_CREAT, 0660, 1);
		i++;
	}
	return (philos);
}
