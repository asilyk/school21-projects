/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:38:23 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 14:01:28 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_init_semaphores(t_sim_data *sim_data)
{
	sem_unlink("forks_sem");
	sem_unlink("output_sem");
	sem_unlink("data_sem");
	sim_data->forks_sem = sem_open("forks_sem",
			O_CREAT, S_IRWXU, sim_data->number_of_philos);
	sim_data->output_sem = sem_open("output_sem",
			O_CREAT, S_IRWXU, 1);
	sim_data->data_sem = sem_open("data_sem",
			O_CREAT, S_IRWXU, 1);
	if (sim_data->forks_sem <= 0
		|| sim_data->output_sem <= 0
		|| sim_data->data_sem <= 0)
	{
		ft_print_error("Error! Failed to create semaphores!\n");
		return (ERROR);
	}
	return (OK);
}

static int	ft_init_sim_data(t_sim_data *sim_data, char **argv)
{
	sim_data->number_of_philos = ft_strict_atoi(argv[1]);
	sim_data->time_to_die = ft_strict_atoi(argv[2]);
	sim_data->time_to_eat = ft_strict_atoi(argv[3]);
	sim_data->time_to_sleep = ft_strict_atoi(argv[4]);
	sim_data->is_stopped = 0;
	if (ft_check_sim_data(sim_data, argv) == ERROR)
		return (ERROR);
	if (ft_init_semaphores(sim_data) == ERROR)
		return (ERROR);
	gettimeofday(&sim_data->start_time, NULL);
	return (OK);
}

static void	ft_init_philos(t_sim_data *sim_data)
{
	int	i;

	i = sim_data->number_of_philos;
	while (--i >= 0)
	{
		sim_data->philos[i].id = i + 1;
		sim_data->philos[i].meals_count = 0;
		sim_data->philos[i].last_meal_time = sim_data->start_time;
		sim_data->philos[i].sim_data = sim_data;
	}
}

int	ft_parse_argv(t_sim_data *sim_data, int argc, char **argv)
{
	if (ft_check_argc(argc) == ERROR)
		return (ERROR);
	if (ft_init_sim_data(sim_data, argv) == ERROR)
		return (ERROR);
	ft_init_philos(sim_data);
	return (OK);
}
