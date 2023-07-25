/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:36:00 by clara             #+#    #+#             */
/*   Updated: 2023/07/21 00:26:40 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_e_next(t_game *game, int img_width, int img_height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'E')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->tabimge[game->x_portal], img_width * j,
					img_height * i);
			if (game->x_portal == 3)
				game->x_portal = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_portal++;
}

void	display_e(t_game *game)
{
	int	img_width;
	int	img_height;

	game->tabimge = malloc(sizeof(void *) * 5);
	game->img_e = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Portal.xpm", &img_width, &img_height);
	game->tabimge[0] = game->img_e;
	game->img_e1 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Portal1.xpm", &img_width, &img_height);
	game->tabimge[1] = game->img_e1;
	game->img_e2 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Portal2.xpm", &img_width, &img_height);
	game->tabimge[2] = game->img_e2;
	game->img_e3 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Portal3.xpm", &img_width, &img_height);
	game->tabimge[3] = game->img_e3;
	display_e_next(game, img_width, img_height);
}

void	display_p_next(t_game *game, int img_width, int img_height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'P')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->img_p1, img_width * j, img_height * i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	display_p(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_p1 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Me.xpm", &img_width, &img_height);
	game->img_p2 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Meup.xpm", &img_width, &img_height);
	game->img_p3 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Meleft.xpm", &img_width, &img_height);
	game->img_p4 = mlx_xpm_file_to_image(game->window.mlx,
			"sprites/Meright.xpm", &img_width, &img_height);
	display_p_next(game, img_width, img_height);
}

void	display_map(t_game *game)
{
	display_background(game);
	display_one(game);
	display_c(game);
	display_e(game);
	display_x(game);
	display_p(game);
}
