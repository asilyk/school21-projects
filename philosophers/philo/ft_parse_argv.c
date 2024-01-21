/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:38:23 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 23:33:55 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_print_error("Error! Invalid number of arguments!\n");
		return (ERROR);
	}
	return (OK);
}

static t_sim_data	*ft_init_sim_data(int argc, char *argv[])
{
	t_sim_data	*sim_data;

	sim_data = (t_sim_data *)malloc(sizeof(t_sim_data));
	if (sim_data == NULL)
	{
		ft_print_error("Error! Failed to allocate memory!\n");
		return (NULL);
	}
	if (pthread_mutex_init(&sim_data->sim_mutex, NULL) != 0)
	{
		free(sim_data);
		ft_print_error("Error! Failed to create mutex!\n");
		return (NULL);
	}
	sim_data->number_of_philos = ft_strict_atoi(argv[1]);
	sim_data->time_to_die = ft_strict_atoi(argv[2]);
	sim_data->time_to_eat = ft_strict_atoi(argv[3]);
	sim_data->time_to_sleep = ft_strict_atoi(argv[4]);
	if (argc == 6)
		sim_data->number_of_meals = ft_strict_atoi(argv[5]);
	else
		sim_data->number_of_meals = 0;
	sim_data->is_stopped = FALSE;
	return (sim_data);
}

static int	ft_check_sim_data(t_sim_data *sim_data)
{
	if (sim_data == NULL)
		return (ERROR);
	if (sim_data->number_of_philos == WRONG_FORMAT
		|| sim_data->time_to_die == WRONG_FORMAT
		|| sim_data->time_to_eat == WRONG_FORMAT
		|| sim_data->time_to_sleep == WRONG_FORMAT
		|| sim_data->number_of_meals == WRONG_FORMAT)
	{
		free(sim_data);
		ft_print_error("Error! Invalid arguments format!\n");
		return (ERROR);
	}
	return (OK);
}

t_sim_data	*ft_parse_argv(int argc, char *argv[])
{
	t_sim_data	*sim_data;

	if (ft_check_argc(argc) == ERROR)
		return (NULL);
	sim_data = ft_init_sim_data(argc, argv);
	if (ft_check_sim_data(sim_data) == ERROR)
		return (NULL);
	gettimeofday(&sim_data->start_time, NULL);
	return (sim_data);
}
