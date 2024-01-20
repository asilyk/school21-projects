/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:08:36 by fabet             #+#    #+#             */
/*   Updated: 2021/10/12 21:20:22 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	ch;

	ch = c;
	ptr = NULL;
	if (*s == ch)
		ptr = (char *)s;
	while (*s)
	{
		s++;
		if (*s == ch)
			ptr = (char *)s;
	}
	return (ptr);
}
