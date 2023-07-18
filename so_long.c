/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:21:18 by chugot            #+#    #+#             */
/*   Updated: 2023/07/12 20:39:02 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char **argv)
{
	char *s2;

	s2 = ".ber";
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], s2) != 0)
	{
			write(1, "Error file is not a .ber\n", 25);
			exit (0);
	}
}

void	treat_map(char **argv, t_map *map)
{
	int	fd;
	int fd1;
	int fd2;

	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	map->map = ft_map(map, fd, fd1, fd2);
	ft_map_copy(map);
	close(fd);
	close(fd1);
	close(fd2);
	error_map(map);
	int i;
	i = 0;
}

void	find_p(t_game *game)
{
	int i;

	i = 0;
	while (game->map.goodmap[i] != NULL)
	{
		if (ft_strchr(game->map.goodmap[i], 'P') != NULL)
		{
			game->player.x = i;
			game->player.y = ft_strchr_x(game->map.goodmap[i], 'P');
		}
		i++;
	}
}

void	find_c(t_game *game)
{
	int i;
	int	j;

	j = 0;
	i = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'C')
				game->total_slimes += 1; 
			j++;
		}
		j = 0;
		i++;
	}
}

void	initialisations(t_game *game)
{
	find_p(game);
	game->count_slimes = 0;
	game->total_slimes = 0;
	game->moves = 0;
	game->flag_portal = 0;
	game->x_slime = 0;
	find_c(game);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_window	window;
	t_map		map;
	t_point player;
	//time_t begin;

	//game.begin = time(NULL);
	check_ber(argv);
	treat_map(argv, &map);
	game.window = window;
	game.player = player;
	game.map = map;
	game.why_not = 1;
	//game.time = begin;
	initialisations(&game);
	game.window.mlx = mlx_init();
	game.window.win = mlx_new_window(game.window.mlx, (32 * (game.map.countchar - 1)), (32 * (game.map.countline)), "So_long");
	
	//mlx_loop_hook(game.window.win, slimes_animation, &game);

	

	display_map(&game);
	mlx_hook(game.window.win, 2, 1L<<0, move_player, &game);
	mlx_hook(game.window.win, 17, 1L<<9, closew, &game);
	mlx_loop(game.window.mlx);
	distroy_all(&game);
	
}

//usleep pour animation -> trop galere
//animer mipas et animer quand C et X.