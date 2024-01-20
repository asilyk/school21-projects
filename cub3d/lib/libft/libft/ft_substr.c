/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:20:42 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:20:43 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!str)
		return (0);
	size = ft_strlen(str + start);
	if (size > len)
		size = len;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len && (start + i) < ft_strlen(str))
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
