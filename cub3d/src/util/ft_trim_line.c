/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:24:34 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:24:35 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

char	*ft_trim_line_back(char *line)
{
	char	*result;

	result = ft_strtrim_back(line, WHITESPACE);
	free(line);
	return (result);
}

char	*ft_trim_line(char *line)
{
	char	*result;

	result = ft_strtrim(line, WHITESPACE);
	free(line);
	return (result);
}
