/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:33:15 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 23:14:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	int			i;
	t_sim_data	*sim_data;

	sim_data = ft_parse_argv(argc, argv);
	if (sim_data == NULL)
		return (ERROR);
	i = 0;
	sim_data->philos = ft_init_philos(sim_data);
	if (sim_data->philos == NULL)
		return (ERROR);
	while (i < sim_data->number_of_philos)
	{
		sim_data->philos[i].pid = fork();
		if (sim_data->philos[i].pid == -1)
		{
			ft_print_error("Error! Failed to create process!\n");
			return (ERROR);
		}
		if	(sim_data->philos[i].pid == 0)
		{
			ft_philo_routine(&sim_data->philos[i]);
			return (OK);
		}
		i++;
	}
	//waitpid(-1, 0, 0);
	i = 0;
	int	ret;
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
	return (OK);
}
