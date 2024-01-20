/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:19:40 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:19:40 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*res;

	size = ft_strlen(s1);
	res = malloc(size + 1);
	if (!(res))
		return (0);
	size = 0;
	while (s1[size])
	{
		res[size] = s1[size];
		size++;
	}
	res[size] = '\0';
	return (res);
}
