/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:18:53 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:18:54 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ptrrealloc(void *buf, int before_size, int after_size)
{
	int		idx;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
	idx = 0;
	while (idx < before_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	free(buf);
	return ((void *)dst);
}
