/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:23:55 by fabet             #+#    #+#             */
/*   Updated: 2022/07/01 11:40:42 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int ms)
{
	struct timeval	start_time;
	struct timeval	actual_time;

	gettimeofday(&start_time, NULL);
	gettimeofday(&actual_time, NULL);
	while (ft_count_timestamp_in_ms(start_time, actual_time) < ms)
	{
		gettimeofday(&actual_time, NULL);
		usleep(10);
	}
}
