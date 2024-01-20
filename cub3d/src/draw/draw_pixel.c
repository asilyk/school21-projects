/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:21:47 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:21:48 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pixel(t_img_info *img_info, int x, int y, int color)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	*(img_info->buf + pixel) = color;
}
