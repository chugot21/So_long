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

void	display_background(t_game *game)
{
	int	i;
	int	j;
	int		img_width;
	int		img_height;
	
	i = 0;
	j = 0;
	game->img_0 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Grass32.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, img_width * j, img_height * i);
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
	int		img_width;
	int		img_height;
	
	i = 0;
	j = 0;
	game->img_1 = mlx_xpm_file_to_image(game->window.mlx, "sprites/GTclear.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_1, img_width * j, img_height * i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	display_c(t_game *game)
{
	int	i;
	int	j;
	int		img_width;
	int		img_height;

	i = 0;
	j = 0;
	game->tabimgc = malloc(sizeof(void *) * 7);
	game->tabimgc[0] = game->img_c = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime1.xpm", &img_width, &img_height);
	game->tabimgc[1] = game->img_c1 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime2.xpm", &img_width, &img_height);
	game->tabimgc[2] = game->img_c2 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime3.xpm", &img_width, &img_height);
	game->tabimgc[3] = game->img_c3 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime4.xpm", &img_width, &img_height);
	game->tabimgc[4] = game->img_c4 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime5.xpm", &img_width, &img_height);
	game->tabimgc[5] = game->img_c5 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime6.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'C')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->tabimgc[game->x_slime], img_width * j, img_height * i);
			if (game->x_slime == 5)
				game->x_slime = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_slime++;
}

void	display_x(t_game *game)
{
	int	i;
	int	j;
	int		img_width;
	int		img_height;
	
	i = 0;
	j = 0;
	game->tabimgx = malloc(sizeof(void *) * 7);
	game->tabimgx[0] = game->img_x = mlx_xpm_file_to_image(game->window.mlx, "sprites/Orc1.xpm", &img_width, &img_height);
	game->tabimgx[1] = game->img_x1 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Orc2.xpm", &img_width, &img_height);
	game->tabimgx[2] = game->img_x2 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Orc3.xpm", &img_width, &img_height);
	game->tabimgx[3] = game->img_x3 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Orc4.xpm", &img_width, &img_height);
	game->tabimgx[4] = game->img_x4 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Orc5.xpm", &img_width, &img_height);
	game->tabimgx[5] = game->img_x5 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Orc6.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'X')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->tabimgx[game->x_enemy], img_width * j, img_height * i);
			if(game->x_enemy == 5)
				game->x_enemy = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_enemy++;
}

void	display_e(t_game *game)
{
	int	i;
	int	j;
	int		img_width;
	int		img_height;
	
	i = 0;
	j = 0;
	game->tabimge = malloc(sizeof(void *) * 5);
	game->tabimge[0] = game->img_e = mlx_xpm_file_to_image(game->window.mlx, "sprites/Portal.xpm", &img_width, &img_height);
	game->tabimge[1] = game->img_e1 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Portal1.xpm", &img_width, &img_height);
	game->tabimge[2] = game->img_e2 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Portal2.xpm", &img_width, &img_height);
	game->tabimge[3] = game->img_e3 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Portal3.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'E')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->tabimge[game->x_portal], img_width * j, img_height * i);
			if (game->x_portal == 3)
				game->x_portal = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_portal++;
}

void	display_p(t_game *game)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;
	
	i = 0;
	j = 0;
	game->img_p1 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Me.xpm", &img_width, &img_height);
	game->img_p2 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meup.xpm", &img_width, &img_height);
	game->img_p3 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meleft.xpm", &img_width, &img_height);
	game->img_p4 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meright.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'P')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p1, img_width * j, img_height * i);
			j++;
		}
		j = 0;
		i++;
	}
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