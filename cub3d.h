/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:48:11 by fabet             #+#    #+#             */
/*   Updated: 2022/11/12 14:43:36 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef int color;

# define WINDOW_HEIGHT	1920
# define WINDOW_WIDTH	1080

# define ON_DESTROY	17
# define NoEventMask	(1L<<12)


typedef struct s_game
{
	void	*mlx;
	void	*win;

	void	*image;
	char	*image_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	color	floor_color;
	color	ceilling_color;
}	t_game;

#endif
