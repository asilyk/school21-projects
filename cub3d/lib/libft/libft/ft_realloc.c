/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:19:23 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:19:24 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	int		i;
	char	*src;
	char	*dst;

	i = 0;
	src = (char *)ptr;
	dst = (char *)malloc(size);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(ptr);
	return ((void *)dst);
}
