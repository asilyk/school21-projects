/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:24:28 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 21:29:37 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (ft_init(argc, argv, &data) == ERROR)
		return (ERROR);
	ft_monitor(data.sim_data, data.philos);
	if (ft_join_threads(&data) == ERROR)
	{
		ft_free(&data);
		return (ERROR);
	}
	ft_free(&data);
	return (OK);
}
