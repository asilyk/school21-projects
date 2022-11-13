/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:33:44 by fabet             #+#    #+#             */
/*   Updated: 2022/11/12 23:15:46 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdlib.h"
#include "cub3d.h"

int	ft_end_game(t_game	*game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(1);
	return (0);
}

unsigned int	ft_create_trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	ft_draw_floor_and_ceilling(t_game	*game)
{
	char	*image_data = game->image_data;
	int		h;
	int		w;

	h = 0;
	w = 0;
	while (h < WINDOW_HEIGHT)
	{
		while (w < WINDOW_WIDTH)
		{
			if (h < WINDOW_HEIGHT / 2)
				*image_data = game->floor_color;
			else
				*image_data = game->ceilling_color;
			w++;
			image_data++;
		}
		h++;
	}

}

int	ft_draw(t_game	*game)
{
	// ft_draw_floor_and_ceilling(game);
	int color = 0xABCDEF;

	if (game->bits_per_pixel != 32)
		color = mlx_get_color_value(game->mlx, color);

	for(int y = 0; y < WINDOW_HEIGHT; ++y)
		for(int x = 0; x < WINDOW_WIDTH; ++x)
		{
			int pixel = (y * game->size_line) + (x * 4);

			if (game->endian == 1)
			{
				game->image_data[pixel + 0] = (color >> 24);
				game->image_data[pixel + 1] = (color >> 16) & 0xFF;
				game->image_data[pixel + 2] = (color >> 8) & 0xFF;
				game->image_data[pixel + 3] = (color) & 0xFF;
			}
			else if (game->endian == 0)
			{
				game->image_data[pixel + 0] = (color) & 0xFF;
				game->image_data[pixel + 1] = (color >> 8) & 0xFF;
				game->image_data[pixel + 2] = (color >> 16) & 0xFF;
				game->image_data[pixel + 3] = (color >> 24);
			}
		}
	mlx_put_image_to_window(game->mlx, game->win,game->image, 0, 0);
	return (0);
}

t_game	*ft_init_game()
{
	t_game	*game = malloc(sizeof(t_game));

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	game->floor_color = ft_create_trgb(50, 0, 100, 0);
	game->ceilling_color = ft_create_trgb(50, 100, 100, 255);
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->image_data = mlx_get_data_addr(game->image, &game->bits_per_pixel, &game->size_line, &game->endian);
	return (game);
}

int	main()
{
	t_game	*game = ft_init_game();
	ft_draw(game);
	mlx_hook(game->win, ON_DESTROY, NoEventMask, ft_end_game, game);
	mlx_loop(game->mlx);
}
