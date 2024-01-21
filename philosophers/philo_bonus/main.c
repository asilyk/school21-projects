/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:33:15 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 14:16:44 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int			i;
	t_sim_data	sim_data;

	if (ft_parse_argv(&sim_data, argc, argv) == ERROR)
		return (ERROR);
	i = 0;
	while (i < sim_data.number_of_philos)
	{
		sim_data.philos[i].pid = fork();
		if (sim_data.philos[i].pid < 0)
			return (1);
		if (sim_data.philos[i].pid == 0)
			ft_philo_routine(&(sim_data.philos[i]));
		usleep(100);
		i++;
	}
	ft_stop_sim(&sim_data);
	return (OK);
}
