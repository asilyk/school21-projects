/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:39:19 by fabet             #+#    #+#             */
/*   Updated: 2021/10/13 01:39:25 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_dstlen(char **dst, size_t dstsize)
{
	char	*dststart;
	size_t	n;
	size_t	dstlen;

	dststart = *dst;
	n = dstsize;
	while (n != 0 && **dst != '\0')
	{
		(*dst)++;
		n--;
	}
	dstlen = *dst - dststart;
	return (dstlen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*osrc;
	size_t	n;
	size_t	dstlen;

	osrc = (char *)src;
	dstlen = ft_find_dstlen(&dst, dstsize);
	n = dstsize - dstlen;
	if (n == 0)
		return (dstlen + ft_strlen(src));
	n--;
	while ((*src != '\0') && (n != 0))
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	while (*src != '\0')
		src++;
	*dst = '\0';
	return (dstlen + (src - osrc));
}
