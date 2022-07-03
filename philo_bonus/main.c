/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:33:15 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 16:01:28 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	t_sim_data	*sim_data;

	sim_data = ft_parse_argv(argc, argv);
	if (sim_data == NULL)
		return (ERROR);
	i = 0;
	while (i < sim_data->number_of_philos)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_print_error("Error! Failed to create process!\n");
			return (ERROR);
		}
		if	(pid == 0)
		{
			t_philo		*philo;
			philo = ft_init_philo(sim_data, i);
			if (philo == NULL)
				return (ERROR);
			ft_philo_routine(philo);
			free(philo);
			return (OK);
		}
		i++;
	}
	while (waitpid(-1, NULL, 0) > 0);
	return (OK);
}
