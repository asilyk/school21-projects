/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:33:15 by fabet             #+#    #+#             */
/*   Updated: 2022/07/03 14:41:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	*ft_init_philo(t_sim_data *sim_data, int id)
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
	printf("Hello from main process!\n");
	return (OK);
}
