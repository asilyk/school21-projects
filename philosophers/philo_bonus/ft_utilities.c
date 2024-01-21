/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:39:03 by fabet             #+#    #+#             */
/*   Updated: 2022/07/04 13:52:50 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strict_atoi(const char *str)
{
	int	result;
	int	counter;

	result = 0;
	counter = 0;
	while (*str)
	{
		if (*str >= 48 && *str <= 57 && counter < 20)
		{
			result = (*str - '0') + result * 10;
			str++;
			counter++;
		}
		else
			return (WRONG_FORMAT);
	}
	return (result);
}

int	ft_count_timestamp(
			t_timeval start_time,
			t_timeval actual_time)
{
	int	seconds;
	int	useconds;

	seconds = actual_time.tv_sec - start_time.tv_sec;
	useconds = actual_time.tv_usec - start_time.tv_usec;
	return (seconds * 1000 + useconds / 1000.0);
}

void	ft_sleep(int ms)
{
	t_timeval	start_time;
	t_timeval	actual_time;

	gettimeofday(&start_time, NULL);
	gettimeofday(&actual_time, NULL);
	while (ft_count_timestamp(start_time, actual_time) < ms)
	{
		gettimeofday(&actual_time, NULL);
		usleep(10);
	}
}

void	ft_print(t_philo *philo, char *action_str)
{
	t_timeval	actual_time;
	int			timestamp;

	if (!(philo->sim_data->is_stopped))
	{
		gettimeofday(&actual_time, NULL);
		timestamp = ft_count_timestamp(philo->sim_data->start_time,
				actual_time);
		sem_wait(philo->sim_data->output_sem);
		printf("%d %d %s\n", timestamp, philo->id, action_str);
		sem_post(philo->sim_data->output_sem);
	}
}

void	ft_print_error(char *error_str)
{
	if (error_str != NULL)
	{
		while (*error_str)
		{
			write(2, error_str, 1);
			error_str++;
		}
	}
}
