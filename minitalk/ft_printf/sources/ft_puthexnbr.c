/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:55:11 by fabet             #+#    #+#             */
/*   Updated: 2021/11/06 06:50:14 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_find_case(const char chcase)
{
	int	icase;

	if (chcase == 'x')
		icase = 87;
	if (chcase == 'X')
		icase = 55;
	return (icase);
}

int	ft_puthexnbr(unsigned int n, const char chcase)
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
	counter = i + 1;
	while (i >= 0)
	{
		if (str[i] > 9)
		{
			ft_putchar_fd(str[i] + ft_find_case(chcase), 1);
			i--;
			continue ;
		}
		ft_putnbr_fd(str[i], 1);
		i--;
	}
	return (counter);
}
