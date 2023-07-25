/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_moves_bis.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:43:31 by chugot            #+#    #+#             */
/*   Updated: 2023/07/21 14:43:34 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player.y += 1;
	end_enemy(game);
	count_slimes(game);
	mlx_put_image_to_window(game->window.mlx, game->window.win,
		game->img_p4, 32 * game->player.y, 32 * game->player.x);
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0,
		32 * (game->player.y - 1), 32 * game->player.x);
}

void	move_left(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player.y -= 1;
	end_enemy(game);
	count_slimes(game);
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p3,
		32 * game->player.y, 32 * game->player.x);
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0,
		32 * (game->player.y + 1), 32 * game->player.x);
}

void	move_up(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player.x -= 1;
	end_enemy(game);
	count_slimes(game);
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p2,
		32 * game->player.y, 32 * game->player.x);
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0,
		32 * game->player.y, 32 * (game->player.x + 1));
}

void	move_down(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player.x += 1;
	end_enemy(game);
	count_slimes(game);
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p1,
		32 * game->player.y, 32 * game->player.x);
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0,
		32 * game->player.y, 32 * (game->player.x - 1));
}

int	move_player(int keycode, t_game *game)
{
	display_c_anim(game);
	display_x_anim(game);
	display_e_anim(game);
	if (keycode == 100 && game->map.goodmap[game->player.x][game->player.y + 1]
		!= '1')
		move_right(game);
	if (keycode == 97 && game->map.goodmap[game->player.x][game->player.y - 1]
		!= '1')
		move_left(game);
	if (keycode == 119 && game->map.goodmap[game->player.x - 1][game->player.y]
		!= '1')
		move_up(game);
	if (keycode == 115 && game->map.goodmap[game->player.x + 1][game->player.y]
		!= '1')
		move_down(game);
	if (keycode == 65307)
		closew(game);
	if (keycode == 32
		&& ((game->map.goodmap[game->player.x + 1][game->player.y] == 'X')
		|| (game->map.goodmap[game->player.x - 1][game->player.y] == 'X')
		|| (game->map.goodmap[game->player.x][game->player.y + 1] == 'X')
		|| (game->map.goodmap[game->player.x][game->player.y - 1] == 'X')))
		destroy_enemy(game);
	return (0);
}
