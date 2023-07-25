/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:49:35 by chugot            #+#    #+#             */
/*   Updated: 2023/07/21 14:49:36 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_background(t_game *game)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	i = 0;
	j = 0;
	game->img_0 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Grass32.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->img_0, img_width * j, img_height * i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	display_one(t_game *game)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	i = 0;
	j = 0;
	game->img_1 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/GTclear.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->img_1, img_width * j, img_height * i);
			j++;
		}
		j = 0;
		i++;
	}
}
