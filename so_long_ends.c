/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ends.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:49 by clara             #+#    #+#             */
/*   Updated: 2023/07/12 20:37:53 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closew(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(0);
}

void    end_enemy(t_game *game)
{
    if (game->map.goodmap[game->player.x][game->player.y] == 'X')
    {
        mlx_destroy_window(game->window.mlx, game->window.win);
		exit(0);
    }
}

void    end_win(t_game *game)
{
    if ((game->map.goodmap[game->player.x][game->player.y] == 'E') && (game->total_slimes == game->count_slimes))
    {
        mlx_destroy_window(game->window.mlx, game->window.win);
		exit(0);
    }
    else
    {
            if ((game->flag_portal == 1) && (game->map.goodmap[game->player.x][game->player.y] != 'E'))
            {
                display_e(game);
                game->flag_portal = 0;
            }
            else if (game->flag_portal == 0 && game->map.goodmap[game->player.x][game->player.y] == 'E')
                game->flag_portal = 1;
    }

}