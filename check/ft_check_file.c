/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:12:24 by fabet             #+#    #+#             */
/*   Updated: 2022/02/25 11:15:56 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

static void	ft_check_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "Error! Invalid number of arguments.\n", 36);
		exit(1);
	}
}

static void	ft_check_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error! File not found.\n", 23);
		exit(1);
	}
	close(fd);
}

static void	ft_check_filename(char *filename)
{
	size_t	i;
	size_t	is_valid_filename;

	i = 1;
	is_valid_filename = 0;
	while (filename[i + 3])
	{
		if (filename[i] == '.' && filename[i + 1] == 'b'
			&& filename[i + 2] == 'e' && filename[i + 3] == 'r')
		{
			is_valid_filename = 1;
		}
		i++;
	}
	if (is_valid_filename == 0)
	{
		write(1, "Error! Invalid filename.\n", 25);
		exit(1);
	}
}

void	ft_check_file(int argc, char *filename)
{
	ft_check_argc(argc);
	ft_check_fd(filename);
	ft_check_filename(filename);
}
