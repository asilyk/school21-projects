/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:09:08 by fabet             #+#    #+#             */
/*   Updated: 2021/10/30 16:18:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_printptr(int str[20], int i)
{
	while (i >= 0)
	{
		if (str[i] > 9)
		{
			ft_putchar_fd(str[i] + 87, 1);
			i--;
			continue ;
		}
		ft_putnbr_fd(str[i], 1);
		i--;
	}
}

int	ft_putptr(uintptr_t n)
{
	int	str[20];
	int	i;
	int	counter;

	i = 0;
	while (n >= 16)
	{
		str[i] = n % 16;
		n /= 16;
		i++;
	}
	str[i] = n;
	ft_putstr_fd("0x", 1);
	counter = i + 3;
	ft_printptr(str, i);
	return (counter);
}
