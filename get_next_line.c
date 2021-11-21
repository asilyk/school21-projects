/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 04:45:47 by fabet             #+#    #+#             */
/*   Updated: 2021/11/21 04:04:56 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_utils.c"

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

	if (read(fd, test, 0) < 0)
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
	static char	*rem;
	char		*str_end;
	char		*str;
	char		*temp;
	int			count;

	str_end = ft_strchr(rem, '\n');
	while (str_end == NULL)
	{
		count = ft_read_buf(fd, &rem);
		if (count == 0)
		{
			str = rem;
			rem = NULL;
			return (str);
		}
		str_end = ft_strchr(rem, '\n');
	}
	str = (char *)malloc(sizeof(char) * (str_end - rem + 1));
	ft_memcpy(str, rem, str_end - rem + 1);
	str[str_end - rem + 1] = '\0';
	temp = rem;
	rem = ft_strdup(rem + ft_strlen(str));
	free(temp);
	return (str);
}

// #include <stdio.h>
// #include <fcntl.h>
// int		main(void)
// {
// 	int		fd;
// 	char	*s;
// 	//int i = 0;

// 	fd = open("gnlTester/files/42_with_nl", O_RDONLY);
// 	s = "\0";
// 	s = get_next_line(fd);
// 	printf("NEW:\t%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("NEW:\t%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("NEW:\t%s", s);
// 	free(s);
// 	// s = get_next_line(fd);
// 	// printf("NEW:\t%s", s);
// 	// free(s);
// 	return (0);
// }
