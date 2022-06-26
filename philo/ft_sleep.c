/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:57:07 by fabet             #+#    #+#             */
/*   Updated: 2022/06/26 09:01:10 by fabet            ###   ########.fr       */
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
