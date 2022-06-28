/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:23:55 by fabet             #+#    #+#             */
/*   Updated: 2022/06/28 20:23:57 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int ms)
{
	struct timeval	start_time;
	struct timeval	actual_time;

	if (gettimeofday(&start_time, NULL) != 0)
	{
		printf("Error! Failed to get time of day!\n");
		return ;
	}
	if (gettimeofday(&actual_time, NULL) != 0)
	{
		printf("Error! Failed to get time of day!\n");
		return ;
	}
	while (ft_count_timestamp_in_ms(start_time, actual_time) < ms)
	{
		if (gettimeofday(&actual_time, NULL) != 0)
		{
			printf("Error! Failed to get time of day!\n");
			return ;
		}
	}
}
