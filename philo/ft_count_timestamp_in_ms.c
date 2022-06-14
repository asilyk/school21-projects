/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_timestamp_in_ms.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:39:23 by fabet             #+#    #+#             */
/*   Updated: 2022/06/13 00:39:50 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_count_timestamp_in_ms(struct timeval start_time, struct timeval actual_time)
{
	long	start_time_in_ms;
	long	actual_time_in_ms;

	start_time_in_ms = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	actual_time_in_ms = actual_time.tv_sec * 1000 + actual_time.tv_usec / 1000;
	return (actual_time_in_ms - start_time_in_ms);
}
