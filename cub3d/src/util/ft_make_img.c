/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:24:14 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:24:15 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "mlx.h"

void	*ft_make_img(void *mlx_ptr, char *xpmFile)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	path = xpmFile;
	img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	free(path);
	if (!img)
	{
		throw_error("XPM Error : check IMG_PATH or fileName");
	}
	return (img);
}
