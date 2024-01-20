/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:50:11 by fabet             #+#    #+#             */
/*   Updated: 2021/10/10 13:42:53 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	ptr = dst;
	while (n != 0)
	{
		*(unsigned char *)dst = *(const unsigned char *)src;
		dst++;
		src++;
		n--;
	}
	return (ptr);
}
