/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:53:45 by fabet             #+#    #+#             */
/*   Updated: 2021/10/12 11:06:23 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	char			*result;

	if (s == NULL)
		return ;
	i = 0;
	result = s;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}
