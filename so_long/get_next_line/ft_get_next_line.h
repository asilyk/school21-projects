/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 05:12:35 by fabet             #+#    #+#             */
/*   Updated: 2022/02/22 11:40:10 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_get_next_line(int fd);

size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strjoin(char *rem, char *buf);

char	*ft_strchr(const char *str, int c);

int		ft_read_buf(int fd, char **rem);

char	*ft_strdup(const char *s1);

#endif
