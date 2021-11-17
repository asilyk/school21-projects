/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 04:45:47 by fabet             #+#    #+#             */
/*   Updated: 2021/11/17 23:54:56 by fabet            ###   ########.fr       */
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

char	*ft_strjoin(char const *rem, char const *buf)
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
			return (NULL);
		ft_memcpy(str, buf, len_buf);
		str[len_buf] = '\0';
		return (str);
	}
	len_rem = ft_strlen(rem);
	str = (char *)malloc(sizeof(char) * (len_rem + len_buf + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, rem, len_rem);
	ft_memcpy(str + ft_strlen(rem), buf, len_buf);
	str[len_rem + len_buf] = '\0';
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

int	ft_read_buf(int fd, char **rem)
{
	char		*buf;
	int			count;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		*rem = NULL;
		return (-1);
	}
	count = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	*rem = ft_strjoin(*rem, buf);
	free(buf);
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*ptr;
	size_t	n;

	n = ft_strlen(s1) + 1;
	s2 = (char *)malloc(n);
	if (s2 == NULL)
	{
		return (NULL);
	}
	ptr = s2;
	while (n != 0)
	{
		*s2 = *s1;
		s1++;
		s2++;
		n--;
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*str_end;
	char		*str;
	char		*temp;
	int			count;

	str = NULL;
	str_end = ft_strchr(rem, '\n');
	while (str_end == NULL)
	{
		//write(1, "EMPTY STRING\n", 14);
		count = ft_read_buf(fd, &rem);
		if ((count < BUFFER_SIZE) || (rem == NULL))
			return (rem
		if (rem == NULL)
			return (NULL);
		str_end = ft_strchr(rem, '\n');
	}
	str = (char *)malloc(sizeof(char) * (str_end - rem + 1));
	ft_memcpy(str, rem, str_end - rem + 1);
	temp = rem;
	rem = ft_strdup(rem + ft_strlen(str));
	free(temp);
	return(str);
}

#include <stdio.h>
#include <fcntl.h>
int		main(void)
{
	int		fd;
	char	*s;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	s = "\0";
	while (s != NULL)
	{
		s = get_next_line(fd);
		printf("new line: %s", s);
		i++;
	}
	printf("new line: %s", s);
	return (0);
}
