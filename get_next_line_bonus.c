/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 04:45:47 by fabet             #+#    #+#             */
/*   Updated: 2021/11/21 14:56:46 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*ptr;
	size_t	n;

	n = ft_strlen(s1) + 1;
	if (n == 1)
		return (NULL);
	s2 = (char *)malloc(n);
	if (s2 == NULL)
		return (NULL);
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

int	ft_read_buf(int fd, char **rem)
{
	char		*buf;
	int			count;
	char		test[1];

	if ((read(fd, test, 0) < 0) || (BUFFER_SIZE < 1))
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	count = read(fd, buf, BUFFER_SIZE);
	if (count == 0)
	{
		free(buf);
		return (count);
	}
	buf[count] = '\0';
	*rem = ft_strjoin(*rem, buf);
	return (count);
}

char	*get_next_line(int fd)
{
	static char	*rem[OPEN_MAX];
	char		*str_end;
	char		*str;
	char		*temp;
	int			count;

	str_end = ft_strchr(rem[fd], '\n');
	while (str_end == NULL)
	{
		count = ft_read_buf(fd, &rem[fd]);
		if (count == 0)
		{
			str = rem[fd];
			rem[fd] = NULL;
			return (str);
		}
		str_end = ft_strchr(rem[fd], '\n');
	}
	str = (char *)malloc(sizeof(char) * (str_end - rem[fd] + 1));
	ft_memcpy(str, rem[fd], str_end - rem[fd] + 1);
	str[str_end - rem[fd] + 1] = '\0';
	temp = rem[fd];
	rem[fd] = ft_strdup(rem[fd] + ft_strlen(str));
	free(temp);
	return (str);
}
