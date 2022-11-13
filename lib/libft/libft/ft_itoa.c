/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:17:20 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:17:21 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_int_len(size_t n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	put_itoa(char *res, int len, size_t n)
{
	if (n < 10)
		res[len] = n + '0';
	else
	{
		put_itoa(res, len - 1, n / 10);
		res[len] = (n % 10) + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	num;
	int		is_minus;

	is_minus = 0;
	if (n <= 0)
	{
		num = -1 * (size_t)n;
		is_minus = 1;
	}
	else
		num = n;
	len = get_int_len(num);
	res = (char *)malloc(sizeof(char) * (len + is_minus + 1));
	if (!res)
		return (0);
	if (is_minus)
		res[0] = '-';
	put_itoa(res + is_minus, len - 1, num);
	res[len + is_minus] = '\0';
	return (res);
}
