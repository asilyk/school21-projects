/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:59:28 by fabet             #+#    #+#             */
/*   Updated: 2021/10/12 16:41:08 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_digitscount(const int n)
{
	size_t	count;
	int		temp;

	if (n == 0)
	{
		return (1);
	}
	count = 0;
	temp = n;
	while (temp)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

static void	ft_fillstr(size_t count, int rank, char *str, int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_memcpy(str, "-2147483648\0", 12);
			return ;
		}
		*str = '-';
		n = -n;
		str++;
	}
	while (count > 0)
	{
		*str = (n / rank) + '0';
		str++;
		n %= rank;
		rank /= 10;
		count--;
	}
	*str = '\0';
}

static int	ft_tenpower(const int n)
{
	int	pow;
	int	temp;

	pow = 1;
	temp = n;
	if (temp < 0)
	{
		temp = -temp;
	}
	while (temp > 1)
	{
		pow *= 10;
		temp--;
	}
	return (pow);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*result;
	int		rank;
	size_t	count;

	count = ft_digitscount(n);
	rank = ft_tenpower(count);
	if (n >= 0)
	{
		str = (char *)malloc(sizeof(char) * (count + 1));
		if (str == NULL)
			return (NULL);
		result = str;
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (count + 2));
		if (str == NULL)
			return (NULL);
		result = str;
	}
	ft_fillstr(count, rank, str, n);
	return (result);
}
