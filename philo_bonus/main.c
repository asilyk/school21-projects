/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:33:15 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 13:19:51 by fabet            ###   ########.fr       */
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
			printf("Hello from child process!\n");
			return (1);
		}
		i++;
	}
}
