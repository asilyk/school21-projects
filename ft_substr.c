/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 01:41:13 by fabet             #+#    #+#             */
/*   Updated: 2021/10/11 03:21:07 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*result;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = (char *)malloc(1);
		*result = '\0';
		return (result);
	}
	if (s[start] && len >= 0)
	{
		substr = (char *)malloc(len + 1);
		if (substr == NULL)
			return (NULL);
		result = substr;
		while (s[start] && len > 0)
		{
			*substr = s[start];
			start++;
			substr++;
			len--;
		}
		*substr = '\0';
		return (result);
	}
	return (NULL);
}
