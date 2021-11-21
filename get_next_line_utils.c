/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 04:45:45 by fabet             #+#    #+#             */
/*   Updated: 2021/11/21 02:34:38 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

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

char	*ft_strjoin(char *rem, char *buf)
{
	char	*str;
	size_t	len_rem;
	size_t	len_buf;

	if (buf == NULL)
		return (NULL);
	len_buf = ft_strlen(buf);
	if (rem == NULL)
	{
		str = (char *)malloc(sizeof(char) * (len_buf + 1));
		if (str == NULL)
		{
			free(buf);
			return (NULL);
		}
		ft_memcpy(str, buf, len_buf);
		str[len_buf] = '\0';
		free(buf);
		return (str);
	}
	len_rem = ft_strlen(rem);
	str = (char *)malloc(sizeof(char) * (len_rem + len_buf + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, rem, len_rem);
	ft_memcpy(str + ft_strlen(rem), buf, len_buf);
	str[len_rem + len_buf] = '\0';
	free(buf);
	free(rem);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;

	ch = c;
	if (str == NULL)
		return (NULL);
	if (*str == ch)
		return ((char *)str);
	while (*str)
	{
		str++;
		if (*str == ch)
			return ((char *)str);
	}
	return (NULL);
}
