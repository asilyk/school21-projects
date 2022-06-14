/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:33:08 by fabet             #+#    #+#             */
/*   Updated: 2022/06/11 16:51:16 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (-1);
	}
	return (result);
}
