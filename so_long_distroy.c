/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_distroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:54:52 by chugot            #+#    #+#             */
/*   Updated: 2023/07/20 00:45:44 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

void	destroy_all_next(t_game *game)
{
	if (game->flag_kill == 1)
	{
		mlx_destroy_image(game->window.mlx, game->img_rip);
		mlx_destroy_image(game->window.mlx, game->img_p1a);
		mlx_destroy_image(game->window.mlx, game->img_p2a);
		mlx_destroy_image(game->window.mlx, game->img_p3a);
		mlx_destroy_image(game->window.mlx, game->img_p4a);
	}
	free(game->tabimgc);
	free(game->tabimgx);
	free(game->tabimge);
	free_map(game->map.map);
	free_map(game->map.goodmap);
	free(game->map.map);
	free(game->map.goodmap);
	mlx_destroy_window(game->window.mlx, game->window.win);
	mlx_destroy_display(game->window.mlx);
	free(game->window.mlx);
}

void	distroy_all(t_game *game)
{
	mlx_destroy_image(game->window.mlx, game->img_0);
	mlx_destroy_image(game->window.mlx, game->img_1);
	mlx_destroy_image(game->window.mlx, game->img_e);
	mlx_destroy_image(game->window.mlx, game->img_e1);
	mlx_destroy_image(game->window.mlx, game->img_e2);
	mlx_destroy_image(game->window.mlx, game->img_e3);
	mlx_destroy_image(game->window.mlx, game->img_c);
	mlx_destroy_image(game->window.mlx, game->img_c1);
	mlx_destroy_image(game->window.mlx, game->img_c2);
	mlx_destroy_image(game->window.mlx, game->img_c3);
	mlx_destroy_image(game->window.mlx, game->img_c4);
	mlx_destroy_image(game->window.mlx, game->img_c5);
	mlx_destroy_image(game->window.mlx, game->img_x);
	mlx_destroy_image(game->window.mlx, game->img_x1);
	mlx_destroy_image(game->window.mlx, game->img_x2);
	mlx_destroy_image(game->window.mlx, game->img_x3);
	mlx_destroy_image(game->window.mlx, game->img_x4);
	mlx_destroy_image(game->window.mlx, game->img_x5);
	mlx_destroy_image(game->window.mlx, game->img_p1);
	mlx_destroy_image(game->window.mlx, game->img_p2);
	mlx_destroy_image(game->window.mlx, game->img_p3);
	mlx_destroy_image(game->window.mlx, game->img_p4);
	destroy_all_next(game);
}
