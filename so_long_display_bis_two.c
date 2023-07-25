/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display_bis_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:52:01 by chugot            #+#    #+#             */
/*   Updated: 2023/07/21 17:52:03 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_c_next(t_game *game, int img_width, int img_height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'C')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->tabimgc[game->x_slime], img_width * j,
					img_height * i);
			if (game->x_slime == 5)
				game->x_slime = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_slime++;
}

void	display_c(t_game *game)
{
	int	img_width;
	int	img_height;

	game->tabimgc = malloc(sizeof(void *) * 7);
	game->img_c = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Slime1.xpm", &img_width, &img_height);
	game->tabimgc[0] = game->img_c;
	game->img_c1 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Slime2.xpm", &img_width, &img_height);
	game->tabimgc[1] = game->img_c1;
	game->img_c2 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Slime3.xpm", &img_width, &img_height);
	game->tabimgc[2] = game->img_c2;
	game->img_c3 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Slime4.xpm", &img_width, &img_height);
	game->tabimgc[3] = game->img_c3;
	game->img_c4 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Slime5.xpm", &img_width, &img_height);
	game->tabimgc[4] = game->img_c4;
	game->img_c5 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Slime6.xpm", &img_width, &img_height);
	game->tabimgc[5] = game->img_c5;
	display_c_next(game, img_width, img_height);
}

void	display_x_next(t_game *game, int img_width, int img_height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'X')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->tabimgx[game->x_enemy], img_width * j,
					img_height * i);
			if (game->x_enemy == 5)
				game->x_enemy = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_enemy++;
}

void	display_x(t_game *game)
{
	int	img_width;
	int	img_height;

	game->tabimgx = malloc(sizeof(void *) * 7);
	game->img_x = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Orc1.xpm", &img_width, &img_height);
	game->tabimgx[0] = game->img_x;
	game->img_x1 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Orc2.xpm", &img_width, &img_height);
	game->tabimgx[1] = game->img_x1;
	game->img_x2 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Orc3.xpm", &img_width, &img_height);
	game->tabimgx[2] = game->img_x2;
	game->img_x3 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Orc4.xpm", &img_width, &img_height);
	game->tabimgx[3] = game->img_x3;
	game->img_x4 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Orc5.xpm", &img_width, &img_height);
	game->tabimgx[4] = game->img_x4;
	game->img_x5 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Orc6.xpm", &img_width, &img_height);
	game->tabimgx[5] = game->img_x5;
	display_x_next(game, img_width, img_height);
}
