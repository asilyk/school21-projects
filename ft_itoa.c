/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:59:28 by fabet             #+#    #+#             */
/*   Updated: 2021/10/12 13:44:23 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	number_digits(const int n)
{
	size_t	count;
	int		temp;

	count = 0;
	temp = n;
	while (temp)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

static int	tenpower(const int n)
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

	rank = tenpower(number_digits(n));
	if (n >= 0)
	{
		str = (char *)malloc(sizeof(char) * (number_digits(n) + 1));
		if (str == NULL)
			return(NULL);
		result = str;
	}
	else
	{
		str = (char *)malloc(sizeof(char) * number_digits(n) + 2);
		if (str == NULL)
			return(NULL);
		result = str;
		if (n == -2147483648)
		{
			ft_memcpy(str, "-2147483648\0", 12);
			return (result);
		}
		*str = '-';
		n = -n;
		str++;
	}
	while (n > 10)
	{
		*str = (n / rank) + '0';
		str++;
		n %= rank;
		rank /= 10;
	}
	*str = (n % 10) + '0';
	str++;
	*str = '\0';
	return (result);
}


#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
	return 0;
}
