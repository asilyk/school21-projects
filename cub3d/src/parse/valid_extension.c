/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:23:35 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:23:36 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"

void	valid_extension(char *fileName)
{
	char	*extension;
	int		diff;

	extension = ft_strrchr(fileName, '.');
	if (!extension)
		throw_error("ExtensionError : file extension is not .cub file!");
	diff = ft_strncmp(extension, ".cub", 5);
	if (diff)
		throw_error("ExtensionError : file extension is not .cub file!");
}
