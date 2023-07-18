/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:36:00 by clara             #+#    #+#             */
/*   Updated: 2023/07/12 20:30:35 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	manage_image(t_game *game, char *xpm_file, int x, int y)
{
	//void	*img;
	//int		img_width;
	//int		img_height;

	//game->img_0 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Grass32.xpm", &img_width, &img_height);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * y, 32 * x);
	//img = mlx_xpm_file_to_image(game->window.mlx, xpm_file, &img_width, &img_height);
	//mlx_put_image_to_window(game->window.mlx, game->window.win, img, img_width * y, img_height * x);
	return (0);
}

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
			//manage_image(game, "sprites/Grass32.xpm", i, j);
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
				//manage_image(game, "sprites/GTclear.xpm", i, j);
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
	//int x;
	int		img_width;
	int		img_height;
	
	//x = 0;
	i = 0;
	j = 0;
	game->tabimg = malloc(4096 * 42);
	game->tabimg[0] = game->img_c = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime1.xpm", &img_width, &img_height);
	game->tabimg[1] = game->img_c1 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime2.xpm", &img_width, &img_height);
	game->tabimg[2] = game->img_c2 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime3.xpm", &img_width, &img_height);
	game->tabimg[3] = game->img_c3 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime4.xpm", &img_width, &img_height);
	game->tabimg[4] = game->img_c4 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime5.xpm", &img_width, &img_height);
	game->tabimg[5] = game->img_c5 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Slime6.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'C')
			{
				printf("%d\n", game->x_slime);
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->tabimg[game->x_slime], img_width * j, img_height * i);
			}
			if (game->x_slime == 5)
				game->x_slime = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_slime++;
}

void	display_e(t_game *game)
{
	int	i;
	int	j;
	int		img_width;
	int		img_height;
	
	i = 0;
	j = 0;
	game->img_e = mlx_xpm_file_to_image(game->window.mlx, "sprites/Portal.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'E')
			{
				//manage_image(game, "sprites/Portal.xpm", i, j);
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_e, img_width * j, img_height * i);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	display_x(t_game *game)
{
	int	i;
	int	j;
	int		img_width;
	int		img_height;
	
	i = 0;
	j = 0;
	game->img_x = mlx_xpm_file_to_image(game->window.mlx, "sprites/Orc.xpm", &img_width, &img_height);
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'X')
			{
				//manage_image(game, "sprites/Orc.xpm", i, j);
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_x, img_width * j, img_height * i);
			}
			j++;
		}
		j = 0;
		i++;
	}
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
			{
				//manage_image(game, "sprites/Me.xpm", i, j);
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p1, img_width * j, img_height * i);
			}
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