/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:10:20 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 14:10:36 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_stop_sim(t_sim_data *sim_data)
{
	int	i;
	int	ret;

	i = 0;
	while (i < sim_data->number_of_philos)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < sim_data->number_of_philos)
				kill(sim_data->philos[i].pid, 15);
			break ;
		}
		i++;
	}
	sem_close(sim_data->forks_sem);
	sem_close(sim_data->output_sem);
	sem_close(sim_data->data_sem);
	sem_unlink("forks_sem");
	sem_unlink("output_sem");
	sem_unlink("data_sem");
}
