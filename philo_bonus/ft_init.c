/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:51:17 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 15:53:09 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*ft_init_philo(t_sim_data *sim_data, int id)
{
	t_philo		*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
	{
		ft_print_error("Error! Failed to allocate memory!\n");
		return (NULL);
	}
	philo->id = id;
	philo->sim_data = sim_data;
	philo->last_meal_time = sim_data->start_time;
	philo->meals_count = 0;
	return (philo);
}
