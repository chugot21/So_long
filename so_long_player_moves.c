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

void	count_moves(t_game *game)
{
	char	*moves;
	int		img_width;
	int		img_height;
	int		i;

	i = 0;
	game->moves += 1;
	moves = ft_itoa(game->moves);
	while (moves[i] != '\0')
	{
		write(1, &moves[i], 1);
		i++;
	}
	write(1, "\n", 1);
	mlx_put_image_to_window(game->window.mlx, game->window.win,
		game->img_1, img_width * 0, img_height * 0);
	mlx_string_put(game->window.mlx, game->window.win,
		10, 20, 0x00F000FF, moves);
	free(moves);
}

void	count_slimes(t_game *game)
{
	count_moves(game);
	if (game->map.goodmap[game->player.x][game->player.y] == 'C')
	{
		game->count_slimes += 1;
		game->map.goodmap[game->player.x][game->player.y] = '0';
	}
	end_win(game);
}

void	destroy_enemy_next(t_game *game)
{
	if (game->map.goodmap[game->player.x - 1][game->player.y] == 'X')
	{
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_p2a, 32 * game->player.y, 32 * game->player.x);
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_rip, 32 * game->player.y, 32 * (game->player.x - 1));
		game->map.goodmap[game->player.x - 1][game->player.y] = '1';
	}
	else if (game->map.goodmap[game->player.x][game->player.y + 1] == 'X')
	{
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_p4a, 32 * game->player.y, 32 * game->player.x);
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_rip, 32 * (game->player.y + 1), 32 * game->player.x);
		game->map.goodmap[game->player.x][game->player.y + 1] = '1';
	}
	else if (game->map.goodmap[game->player.x][game->player.y - 1] == 'X')
	{
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_p3a, 32 * game->player.y, 32 * game->player.x);
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_rip, 32 * (game->player.y - 1), 32 * game->player.x);
		game->map.goodmap[game->player.x][game->player.y - 1] = '1';
	}
}

void	destroy_enemy_second(t_game *game)
{
	int	img_width;
	int	img_height;

	if (game->map.goodmap[game->player.x + 1][game->player.y] == 'X')
	{
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_p1a, 32 * game->player.y, 32 * game->player.x);
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->img_rip, 32 * game->player.y, 32 * (game->player.x + 1));
		game->map.goodmap[game->player.x + 1][game->player.y] = '1';
	}
	destroy_enemy_next(game);
}

void	destroy_enemy(t_game *game)
{
	int	img_width;
	int	img_height;

	if (game->flag_kill == 0)
	{
		game->img_rip = mlx_xpm_file_to_image(game->window.mlx,
				"sprites/RIP.xpm", &img_width, &img_height);
		game->img_p1a = mlx_xpm_file_to_image(game->window.mlx,
				"sprites/Medownattack.xpm", &img_width, &img_height);
		game->img_p2a = mlx_xpm_file_to_image(game->window.mlx,
				"sprites/Meupattack.xpm", &img_width, &img_height);
		game->img_p3a = mlx_xpm_file_to_image(game->window.mlx,
				"sprites/Meleftattack.xpm", &img_width, &img_height);
		game->img_p4a = mlx_xpm_file_to_image(game->window.mlx,
				"sprites/Merightattack.xpm", &img_width, &img_height);
		game->flag_kill++;
	}
	destroy_enemy_next(game);
}
