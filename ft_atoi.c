/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:41:19 by fabet             #+#    #+#             */
/*   Updated: 2021/10/10 14:57:51 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_result(int counter, int result, int sign)
{
	if (counter >= 20)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return (result * sign);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	counter;

	sign = 1;
	result = 0;
	counter = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57 && counter < 20)
	{
		result = (*str - '0') + result * 10;
		str++;
		counter++;
	}
	return (ft_get_result(counter, result, sign));
}
