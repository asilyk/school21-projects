/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:54:45 by fabet             #+#    #+#             */
/*   Updated: 2022/02/27 13:53:53 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_map.h"

static void	ft_get_map_height_and_width(t_map *map, char *filename)
{
	int		fd;
	int		height;
	int		width;
	char	ch;

	fd = open(filename, O_RDONLY);
	height = 0;
	width = 0;
	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
		{
			height++;
			width = 0;
		}
		width++;
	}
	width--;
	height++;
	close(fd);
	map->height = height;
	map->width = width;
}

static size_t	ft_get_victory_score(char *filename)
{
	int		fd;
	int		count;
	char	ch;

	fd = open(filename, O_RDONLY);
	count = 0;
	while (read(fd, &ch, 1))
	{
		if (ch == 'C')
			count++;
	}
	close(fd);
	return (count);
}

static void	ft_find_player_position(t_map	*map)
{
	char			**components;
	size_t			x;
	size_t			y;

	components = map->components;
	x = 0;
	y = 0;
	while (y < map->height)
	{
		if (components[y][x] == 'P')
		{
			map->player_position_x = x;
			map->player_position_y = y;
			return ;
		}
		x++;
		if (x >= map->width)
		{
			y++;
			x = 0;
		}
	}
	map->player_position_x = 0;
	map->player_position_y = 0;
}

void	ft_get_map_data(char *filename, t_vars *vars)
{
	int			fd;
	char		*new_line;
	char		**components;
	char		**result;

	ft_get_map_height_and_width(vars->map, filename);
	components = (char **)malloc(sizeof(char *) * (vars->map->height + 1));
	if (components == NULL)
		ft_end_game(vars);
	result = components;
	fd = open(filename, O_RDONLY);
	new_line = ft_get_next_line(fd);
	while (new_line)
	{
		*components = new_line;
		components++;
		new_line = ft_get_next_line(fd);
	}
	*components = NULL;
	close(fd);
	vars->map->components = result;
}

void	ft_get_map(char *filename, t_vars *vars)
{
	vars->map = (t_map *)malloc(sizeof(t_map));
	if (vars->map == NULL)
		ft_end_game(vars);
	ft_get_map_data(filename, vars);
	if (vars->map->components == NULL)
		ft_end_game(vars);
	vars->map->victory_score = ft_get_victory_score(filename);
	vars->map->current_score = 0;
	vars->map->number_of_movements = 0;
	vars->map->game_is_over = FALSE;
	vars->mlx = NULL;
	vars->win = NULL;
	ft_check_size(vars);
	ft_find_player_position(vars->map);
}
