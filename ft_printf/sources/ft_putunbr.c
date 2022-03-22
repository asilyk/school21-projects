/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 22:36:50 by fabet             #+#    #+#             */
/*   Updated: 2021/11/06 06:01:24 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_print_digits(unsigned int *n, unsigned long *size)
{
	char	c;

	c = (*n / *size) + 48;
	*n %= *size;
	write(1, &c, 1);
	*size /= 10;
}

static int	ft_print_zero(int n)
{
	char	c;

	c = 0;
	c = n + 48;
	write(1, &c, 1);
	return (1);
}

int	ft_putunbr(unsigned int n)
{
	unsigned long	size;
	unsigned int	temp;
	int				counter;

	size = 1;
	counter = 0;
	if (n == 0)
	{
		ft_print_zero(n);
		return (1);
	}
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		size *= 10;
	}
	size /= 10;
	while (size > 0)
	{
		ft_print_digits(&n, &size);
		counter++;
	}
	return (counter);
}
