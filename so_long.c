/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:21:18 by chugot            #+#    #+#             */
/*   Updated: 2023/07/20 23:33:20 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char **argv)
{
	char	*s2;

	s2 = ".ber";
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], s2) != 0)
	{
		write(1, "Error file is not a .ber\n", 25);
		exit (0);
	}
}

void	error_map(t_map *map)
{
	error_exit(map);
	error_position(map);
	error_items(map);
	error_rectangle(map);
	error_wall(map);
	error_path(map);
}

void	treat_map(char **argv, t_map *map)
{
	int	fd;
	int	fd1;
	int	fd2;

	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	map->map = ft_map(map, fd, fd1, fd2);
	map->countchar = ft_strlen(map->map[0]);
	ft_map_copy(map);
	close(fd);
	close(fd1);
	close(fd2);
	error_map(map);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_window	window;
	t_map		map;
	t_point		player;

	check_ber(argv);
	treat_map(argv, &map);
	game.window = window;
	game.player = player;
	game.map = map;
	initialisations(&game);
	game.window.mlx = mlx_init();
	game.window.win = mlx_new_window (game.window.mlx,
			(32 * (game.map.countchar - 1)),
			(32 * (game.map.countline)), "So_long");
	display_map(&game);
	mlx_hook(game.window.win, 2, 1L << 0, move_player, &game);
	mlx_hook(game.window.win, 17, 1L << 9, closew, &game);
	mlx_loop(game.window.mlx);
}
