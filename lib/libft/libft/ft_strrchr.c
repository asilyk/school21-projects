/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:20:31 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:20:31 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	size;
	int	i;

	size = ft_strlen(src);
	if (c == 0)
		return ((char *)&src[size]);
	i = 0;
	while (i < size)
	{
		if (src[size - i - 1] == (char)c)
			return ((char *)&src[size - i - 1]);
		i++;
	}
	return (0);
}
