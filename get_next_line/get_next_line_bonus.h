/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 05:12:43 by fabet             #+#    #+#             */
/*   Updated: 2021/11/21 05:13:06 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strjoin(char *rem, char *buf);

char	*ft_strchr(const char *str, int c);

int		ft_read_buf(int fd, char **rem);

char	*ft_strdup(const char *s1);

#endif
