/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_timestamp_in_ms.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:39:23 by fabet             #+#    #+#             */
/*   Updated: 2022/06/28 20:23:00 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_count_timestamp_in_ms(
			struct timeval start_time,
			struct timeval actual_time)
{
	long	seconds;
	long	useconds;

	seconds = actual_time.tv_sec - start_time.tv_sec;
	useconds = actual_time.tv_usec - start_time.tv_usec;
	return (seconds * 1000 + useconds / 1000.0);
}
