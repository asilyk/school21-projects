/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:20:32 by fabet             #+#    #+#             */
/*   Updated: 2021/10/12 19:39:46 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = c;
	if (*s == ch)
		return ((char *)s);
	while (*s)
	{
		s++;
		if (*s == ch)
			return ((char *)s);
	}
	return (NULL);
}
