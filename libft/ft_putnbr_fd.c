/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 07:52:46 by fabet             #+#    #+#             */
/*   Updated: 2021/10/12 16:31:12 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_print_digits(int *n, int *size, int fd)
{
	char	c;

	c = (*n / *size) + 48;
	*n %= *size;
	write(fd, &c, 1);
	*size /= 10;
}

static void	ft_print_zero(int n, int fd)
{
	char	c;

	c = 0;
	c = n + 48;
	write(fd, &c, 1);
}

static void	ft_print_minus(int *n, int fd)
{
	char	c;

	c = '-';
	write(fd, &c, 1);
	*n = -*n;
}

static void	ft_print_maxmin(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n == 2147483647)
		ft_putstr_fd("2147483647", fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	size;
	int	temp;

	if (n == -2147483648 || n == 2147483647)
	{
		ft_print_maxmin(n, fd);
		return ;
	}
	size = 1;
	if (n == 0)
	{
		ft_print_zero(n, fd);
		return ;
	}
	if (n < 0)
		ft_print_minus(&n, fd);
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		size *= 10;
	}
	size /= 10;
	while (size > 0)
		ft_print_digits(&n, &size, fd);
}
