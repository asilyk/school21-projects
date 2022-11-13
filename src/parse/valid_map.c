/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:23:44 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:23:45 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "parse.h"

static void	count_player(char *line, int *player_cnt)
{
	int		col;

	col = 0;
	while (line[col])
	{
		if (ft_strchr("NSEW", line[col]))
		{
			(*player_cnt)++;
			if (*player_cnt != 1)
				throw_error("InvalidMapError : too many player exist");
		}
		col++;
	}
}

static char	**map_dup(t_map_info *map_info)
{
	int		row;
	int		col;
	int		size;
	char	**map;

	map = ft_calloc(map_info->height, sizeof(char *));
	if (!map)
		throw_error("Error : malloc error.");
	row = -1;
	while (++row < map_info->height)
	{
		map[row] = ft_calloc(map_info->width + 1, sizeof(char));
		col = -1;
		size = ft_strlen(map_info->map[row]);
		while (++col < size)
			map[row][col] = map_info->map[row][col];
		while (col < map_info->width)
		{
			map[row][col] = SPACE;
			col++;
		}
	}
	return (map);
}

void	valid_map(t_map_info *map_info)
{
	char		**map;
	char		*line;
	int			row;
	int			player_cnt;

	row = 0;
	player_cnt = 0;
	map = map_dup(map_info);
	while (row < map_info->height)
	{
		line = map[row];
		count_player(line, &player_cnt);
		valid_edge_wall(line, map_info->height, row);
		valid_inner_wall(line, map, map_info->height, row);
		row++;
	}
	if (player_cnt != 1)
		throw_error("InvalidMapError : player must exist only one");
	row = -1;
	while (++row < map_info->height)
		free(map[row]);
	free(map);
}
