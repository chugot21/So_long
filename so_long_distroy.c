/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_distroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:54:52 by chugot            #+#    #+#             */
/*   Updated: 2023/07/14 17:54:54 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    distroy_all(t_game *game)
{
    //free(); map1 et map2
    mlx_destroy_image(game->window.mlx, game->img_0);
    mlx_destroy_image(game->window.mlx, game->img_1);
    mlx_destroy_image(game->window.mlx, game->img_e);
    mlx_destroy_image(game->window.mlx, game->img_c);
    mlx_destroy_image(game->window.mlx, game->img_c1);
    mlx_destroy_image(game->window.mlx, game->img_c2);
    mlx_destroy_image(game->window.mlx, game->img_c3);
    mlx_destroy_image(game->window.mlx, game->img_c4);
    mlx_destroy_image(game->window.mlx, game->img_c5);
    mlx_destroy_image(game->window.mlx, game->img_x);
    mlx_destroy_image(game->window.mlx, game->img_p1);
    mlx_destroy_image(game->window.mlx, game->img_p2);
    mlx_destroy_image(game->window.mlx, game->img_p3);
    mlx_destroy_image(game->window.mlx, game->img_p4);

    mlx_destroy_window(game->window.mlx, game->window.win);
    mlx_destroy_display(game->window.mlx);
}
