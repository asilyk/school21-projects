/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:01:03 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 14:02:49 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_print_error("Error! Invalid number of arguments!\n");
		return (ERROR);
	}
	return (OK);
}

int	ft_check_sim_data(t_sim_data *sim_data, char **argv)
{
	if (sim_data->number_of_philos < 2
		|| sim_data->time_to_die < 0
		|| sim_data->time_to_eat < 0
		|| sim_data->time_to_sleep < 0
		|| sim_data->number_of_philos > 200)
	{
		ft_print_error("Error! Invalid arguments format!\n");
		return (ERROR);
	}
	if (argv[5])
	{
		sim_data->number_of_meals = ft_strict_atoi(argv[5]);
		if (sim_data->number_of_meals <= 0)
		{
			ft_print_error("Error! Invalid arguments format!\n");
			return (ERROR);
		}
	}
	else
		sim_data->number_of_meals = -1;
	if (sim_data->number_of_meals == 1)
		sim_data->number_of_meals++;
	return (OK);
}
