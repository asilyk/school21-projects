/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:24:04 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:24:05 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_get_line(int fd)
{
	char	*line;
	char	eol;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	eol = line[len - 1];
	if (eol == '\n')
		line[len - 1] = 0;
	return (line);
}
