/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_edge_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:23:29 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:23:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"

static void	check_edge(char *line, int start, int last)
{
	if (line[last] != WALL)
		throw_error("InvalidMapError : invalid wall of edge!");
	if (line[start] != WALL)
		throw_error("InvalidMapError : invalid wall of edge!");
}

static void	check_first_last_edge(char *line, int start, int last)
{
	if (line[last] != WALL)
		throw_error("InvalidMapError : invalid wall of edge!");
	while (start < last)
	{
		if (line[start] != WALL && line[start] != SPACE)
			throw_error("InvalidMapError : invalid wall of edge!");
		start++;
	}
}

void	valid_edge_wall(char *line, int height, int row)
{
	int		col;
	int		start;
	int		last;

	col = 0;
	start = ft_strchr(line, WALL) - line;
	last = ft_strrchr(line, WALL) - line;
	while (col < start)
	{
		if (line[col] != SPACE)
			throw_error("InvalidMapError : invalid edge wall!");
		col++;
	}
	if (row == 0 || row == height - 1)
		check_first_last_edge(line, start, last);
	else
		check_edge(line, start, last);
}
