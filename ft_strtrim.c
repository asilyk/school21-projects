/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:12:20 by fabet             #+#    #+#             */
/*   Updated: 2021/10/14 05:24:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_issetchar(char ch, char const *set)
{
	char	*ptr;

	ptr = (char *)set;
	while (*ptr)
	{
		if (*ptr == ch)
			return (1);
		ptr++;
	}
	return (0);
}

static char	*ft_emptystr(void)
{
	char	*newstr;

	newstr = (char *)malloc(1);
	*newstr = '\0';
	return (newstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*left;
	char	*right;
	char	*newstr;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	left = (char *)s1;
	right = (char *)s1;
	while (ft_issetchar(*left, set))
		left++;
	while (*right)
		right++;
	if (right <= left)
		return (ft_emptystr());
	right--;
	while (ft_issetchar(*right, set))
		right--;
	if (right <= s1)
		return (ft_emptystr());
	newstr = (char *)malloc(right - left + 2);
	if (newstr == NULL)
		return (NULL);
	ft_memcpy(newstr, left, right - left + 1);
	newstr[right - left + 1] = '\0';
	return (newstr);
}
