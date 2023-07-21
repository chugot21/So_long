/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ends.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:49 by clara             #+#    #+#             */
/*   Updated: 2023/07/20 00:42:51 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closew(t_game *game)
{
    distroy_all(game);
    write(1, "Don't give up... It's for the weak !\n", 37);
	exit(0);
}

void    end_enemy(t_game *game)
{
    if (game->map.goodmap[game->player.x][game->player.y] == 'X')
    {
        distroy_all(game);
        write(1, "You have been killed...\n...\n...\nShame on you, LOOSER !\n", 55);
		exit(0);
    }
}

void    end_win(t_game *game)
{
    int cmd;

    if ((game->map.goodmap[game->player.x][game->player.y] == 'E') && (game->total_slimes == game->count_slimes))
    {
        distroy_all(game);
        write(1, "YOU WIN ! WELL DONE !\n", 22);
        cmd = system("curl parrot.live");
        if (cmd != 0)
            write(1, "Error command system\n", 21);
		exit(0);
    }
}