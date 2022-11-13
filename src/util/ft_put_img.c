/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:24:19 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:24:20 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"

void	ft_put_img(t_gl *gl, void *img, int x, int y)
{
	mlx_put_image_to_window(gl->mlx_ptr, gl->win_ptr, img, x, y);
}
