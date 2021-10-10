/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:16:59 by fabet             #+#    #+#             */
/*   Updated: 2021/10/10 19:07:09 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*odst;
	char	*osrc;
	size_t	n;
	size_t	dlen;

	odst = dst;
	osrc = (char *)src;
	n = dstsize;
	while (n != 0 && *dst != '\0')
	{
		dst++;
		n--;
	}
	dlen = dst - odst;
	n = dstsize - dlen;
	if (n == 0)
	{
		return (dlen + ft_strlen(src));
	}
	n--;
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
