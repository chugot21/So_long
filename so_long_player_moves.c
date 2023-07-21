/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:59:19 by clara             #+#    #+#             */
/*   Updated: 2023/07/20 23:33:57 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    count_moves(t_game *game)
{
    int		img_width;
	int		img_height;
    char *moves;
    int i;

    i = 0;
    game->moves += 1;
    moves = ft_itoa(game->moves);
    while (moves[i] != '\0')
    {
        write(1, &moves[i], 1);
        i++;
    }
    write(1, "\n", 1);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_1, img_width * 0, img_height * 0);
    mlx_string_put(game->window.mlx, game->window.win, 10, 20, 0x00F000FF, moves);
}

void    count_slimes(t_game *game)
{
    count_moves(game);
    if (game->map.goodmap[game->player.x][game->player.y] == 'C')
    {
        game->count_slimes += 1;
        game->map.goodmap[game->player.x][game->player.y] = '0';
    }
    end_win(game);
}

void    move_right(t_game *game)
{
    int		img_width;
	int		img_height;

	game->player.y += 1;
    end_enemy(game);
    count_slimes(game);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p4, 32 * game->player.y, 32 * game->player.x);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * (game->player.y - 1), 32 * game->player.x);
}

void    move_left(t_game *game)
{
    int		img_width;
	int		img_height;

	game->player.y -= 1;
    end_enemy(game);
    count_slimes(game);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p3, 32 * game->player.y, 32 * game->player.x);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * (game->player.y + 1), 32 * game->player.x);
}

void    move_up(t_game *game)
{
    int		img_width;
	int		img_height;

	game->player.x -= 1;
    end_enemy(game);
    count_slimes(game);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p2, 32 * game->player.y, 32 * game->player.x);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y, 32 * (game->player.x + 1));
}

void    move_down(t_game *game)
{
    int		img_width;
	int		img_height;

	game->player.x += 1;
    end_enemy(game);
    count_slimes(game);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p1, 32 * game->player.y, 32 * game->player.x);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y, 32 * (game->player.x - 1));
}

void    destroy_enemy_next(t_game *game)
{
    if (game->map.goodmap[game->player.x - 1][game->player.y] == 'X')
    {
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p2a, 32 * game->player.y, 32 * game->player.x);
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_rip, 32 * game->player.y, 32 * (game->player.x - 1));
        game->map.goodmap[game->player.x - 1][game->player.y] = '1';
    }
    else if (game->map.goodmap[game->player.x][game->player.y + 1] == 'X')
    {
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p4a, 32 * game->player.y, 32 * game->player.x);
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_rip, 32 * (game->player.y + 1), 32 * game->player.x);
        game->map.goodmap[game->player.x][game->player.y + 1] = '1';
    }
    else if (game->map.goodmap[game->player.x][game->player.y - 1] == 'X')
    {
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p3a, 32 * game->player.y, 32 * game->player.x);
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_rip, 32 * (game->player.y - 1), 32 * game->player.x);
        game->map.goodmap[game->player.x][game->player.y - 1] = '1';
    }
}

void    destroy_enemy(t_game *game)
{
    int		img_width;
	int		img_height;
    
    if (game->flag_kill == 0)
    {
        game->img_rip = mlx_xpm_file_to_image(game->window.mlx, "sprites/RIP.xpm", &img_width, &img_height);
        game->img_p1a = mlx_xpm_file_to_image(game->window.mlx, "sprites/Medownattack.xpm", &img_width, &img_height);
        game->img_p2a = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meupattack.xpm", &img_width, &img_height);
        game->img_p3a = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meleftattack.xpm", &img_width, &img_height);
        game->img_p4a = mlx_xpm_file_to_image(game->window.mlx, "sprites/Merightattack.xpm", &img_width, &img_height);
        game->flag_kill++;
    }
    if (game->map.goodmap[game->player.x + 1][game->player.y] == 'X')
    {
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p1a, 32 * game->player.y, 32 * game->player.x);
        mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_rip, 32 * game->player.y, 32 * (game->player.x + 1));
        game->map.goodmap[game->player.x + 1][game->player.y] = '1';
    }
    destroy_enemy_next(game);
}

int	move_player(int keycode, t_game *game)
{
    display_c(game);
    display_x(game);
    display_e(game);
	if (keycode == 100 && game->map.goodmap[game->player.x][game->player.y + 1] != '1')//100
        move_right(game);
    if (keycode == 113 && game->map.goodmap[game->player.x][game->player.y - 1] != '1')//97
        move_left(game);
    if (keycode == 122 && game->map.goodmap[game->player.x - 1][game->player.y] != '1')//119
        move_up(game);
    if (keycode == 115 && game->map.goodmap[game->player.x + 1][game->player.y] != '1')//115
        move_down(game);
    if (keycode == 65307)
        closew(game);
    if (keycode == 32 && ((game->map.goodmap[game->player.x + 1][game->player.y] == 'X') || (game->map.goodmap[game->player.x - 1][game->player.y] == 'X') 
        || (game->map.goodmap[game->player.x][game->player.y + 1] == 'X') || (game->map.goodmap[game->player.x][game->player.y - 1] == 'X')))
        destroy_enemy(game);
	return (0);
}