/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:59:19 by clara             #+#    #+#             */
/*   Updated: 2023/07/12 20:44:53 by clara            ###   ########.fr       */
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
    //manage_image(game, "sprites/GTclear.xpm", 0, 0);
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
	//manage_image(game, "sprites/Meright.xpm", game->player.x, game->player.y);
    //game->img_p4 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meright.xpm", &img_width, &img_height);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p4, 32 * game->player.y, 32 * game->player.x);
    //game->img_0 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Grass32.xpm", &img_width, &img_height);
    //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y - 1, 32 * game->player.x);
	manage_image(game, "sprites/Grass32.xpm", game->player.x, game->player.y - 1);
}

void    move_left(t_game *game)
{
    int		img_width;
	int		img_height;

	game->player.y -= 1;
    end_enemy(game);
    count_slimes(game);
	//manage_image(game, "sprites/Meleft.xpm", game->player.x, game->player.y);
    //game->img_p3 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meleft.xpm", &img_width, &img_height);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p3, 32 * game->player.y, 32 * game->player.x);
    //game->img_0 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Grass32.xpm", &img_width, &img_height);
    //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y + 1, 32 * game->player.x);
	manage_image(game, "sprites/Grass32.xpm", game->player.x, game->player.y + 1);
}

void    move_up(t_game *game)
{
    int		img_width;
	int		img_height;

	game->player.x -= 1;
    end_enemy(game);
    count_slimes(game);
	//manage_image(game, "sprites/Meup.xpm", game->player.x, game->player.y);
    //game->img_p2 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Meup.xpm", &img_width, &img_height);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p2, 32 * game->player.y, 32 * game->player.x);
    //game->img_0 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Grass32.xpm", &img_width, &img_height);
    //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y, 32 * game->player.x + 1);
	manage_image(game, "sprites/Grass32.xpm", game->player.x + 1, game->player.y);
}

void    move_down(t_game *game)
{
    int		img_width;
	int		img_height;

	game->player.x += 1;
    end_enemy(game);
    count_slimes(game);
	//manage_image(game, "sprites/Me.xpm", game->player.x, game->player.y);
    //game->img_p1 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Me.xpm", &img_width, &img_height);
    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_p1, 32 * game->player.y, 32 * game->player.x);
    //game->img_0 = mlx_xpm_file_to_image(game->window.mlx, "sprites/Grass32.xpm", &img_width, &img_height);
    //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y, 32 * game->player.x - 1);
	manage_image(game, "sprites/Grass32.xpm", game->player.x - 1, game->player.y);
}

void    destroy_enemy(t_game *game)
{
    if (game->map.goodmap[game->player.x + 1][game->player.y] == 'X')
    {
        manage_image(game, "sprites/Grass32.xpm", game->player.x + 1, game->player.y);
        //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y, 32 * game->player.x + 1);
        game->map.goodmap[game->player.x + 1][game->player.y] = '0';
        //voir animation enemy et peut utiliser manage image
    }
    if (game->map.goodmap[game->player.x - 1][game->player.y] == 'X')
    {
        manage_image(game, "sprites/Grass32.xpm", game->player.x - 1, game->player.y);
        //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y, 32 * game->player.x - 1);
        game->map.goodmap[game->player.x - 1][game->player.y] = '0';
    }
    if (game->map.goodmap[game->player.x][game->player.y + 1] == 'X')
    {
        manage_image(game, "sprites/Grass32.xpm", game->player.x, game->player.y + 1);
       //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y + 1, 32 * game->player.x);
        game->map.goodmap[game->player.x][game->player.y + 1] = '0';
    }
    if (game->map.goodmap[game->player.x][game->player.y - 1] == 'X')
    {
        manage_image(game, "sprites/Grass32.xpm", game->player.x, game->player.y - 1);
        //mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_0, 32 * game->player.y - 1, 32 * game->player.x);
        game->map.goodmap[game->player.x][game->player.y - 1] = '0';
    }
}

int    slimes_animation(t_game *game)
{
    int count;
    int	i;
	int	j;
	int	img_width;
	int	img_height;
	
    count = 0;
    //while (count <= 100)
	//{
        printf("test\n");
        usleep(1000);
        /*i = 0;
        while (game->map.goodmap[i] != NULL)
        {
            j = 0;
            while (game->map.goodmap[i][j] != '\n')
            {
                if (game->map.goodmap[i][j] == 'C')
                {
                    //manage_image(game, "sprites/Slime1.xpm", i, j);
                    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_c, img_width * j, img_height * i);
                    usleep(10000);
                    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_c1, img_width * j, img_height * i);
                    usleep(10000);
                    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_c2, img_width * j, img_height * i);
                    usleep(10000);
                    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_c3, img_width * j, img_height * i);
                    usleep(10000);
                    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_c4, img_width * j, img_height * i);
                    usleep(10000);
                    mlx_put_image_to_window(game->window.mlx, game->window.win, game->img_c5, img_width * j, img_height * i);
                    usleep(10000);
                }
                j++;
            }
            j = 0;
            i++;
        }
        count++;
    }*/
    return(0);
}

int	move_player(int keycode, t_game *game)
{
	if (keycode == 100 && game->map.goodmap[game->player.x][game->player.y + 1] != '1')
        move_right(game);
    if (keycode == 97 && game->map.goodmap[game->player.x][game->player.y - 1] != '1')
        move_left(game);
    if (keycode == 119 && game->map.goodmap[game->player.x - 1][game->player.y] != '1')
        move_up(game);
    if (keycode == 115 && game->map.goodmap[game->player.x + 1][game->player.y] != '1')
        move_down(game);
    if (keycode == 65307)
    {
        mlx_destroy_window(game->window.mlx, game->window.win);
		exit(0);
    }
    if (keycode == 32 && ((game->map.goodmap[game->player.x + 1][game->player.y] == 'X') || (game->map.goodmap[game->player.x - 1][game->player.y] == 'X') 
        || (game->map.goodmap[game->player.x][game->player.y + 1] == 'X') || (game->map.goodmap[game->player.x][game->player.y - 1] == 'X')))
        destroy_enemy(game);
    //slimes_animation(game);
	return (0);
}