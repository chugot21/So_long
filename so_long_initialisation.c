/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:02:21 by chugot            #+#    #+#             */
/*   Updated: 2023/07/21 15:02:22 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_copy_next(t_map *map, int i, int j)
{
	i = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\n')
		{
			map->goodmap[i][j] = map->map[i][j];
			j++;
		}
		map->goodmap[i][j] = '\n';
		j = 0;
		i++;
	}
	map->goodmap[i] = NULL;
}

void	ft_map_copy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->goodmap = ft_calloc(sizeof(char *), (map->countline + 1)); // modif
	if (!map->goodmap)
		exit (0);
	while (map->map[i] != NULL)
	{
		map->goodmap[i] = ft_calloc(sizeof(char), (map->countchar + 1)); // modif
		if (!map->goodmap[i])
			exit (0);
		i++;
	}
	ft_map_copy_next(map, i, j);
}

int	find_p(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.goodmap[i] != NULL)
	{
		if (ft_strchr(game->map.goodmap[i], 'P') != NULL)
		{
			game->player.x = i;
			game->player.y = ft_strchr_y(game->map.goodmap[i], 'P');
			return (0);
		}
		i++;
	}
	return (0);
}

void	find_c(t_game *game)
{
	int	i;
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
	game->x_slime = 0;
	game->x_enemy = 0;
	game->x_portal = 0;
	game->flag_kill = 0;
	game->thread = 0;
	find_c(game);
}