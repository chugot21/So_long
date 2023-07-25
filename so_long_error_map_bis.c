/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_map_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:51:44 by chugot            #+#    #+#             */
/*   Updated: 2023/07/21 15:51:45 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_wall(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->map[i][j] != '\n')
	{
		if (map->map[i][j] != '1')
		{
			write(1, "Error map is not closed by wall\n", 31);
			exit (0);
		}
		j++;
	}
	error_wall_2(map, i, j);
}

void	error_path3(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if ((ft_strchr(map->map[i], 'E') != NULL)
			|| (ft_strchr(map->map[i], 'C') != NULL))
		{
			write(1, "Error there is no path available\n", 33);
			exit (0);
		}
		i++;
	}
}

void	error_path2_next(t_map *map, t_point player)
{
	if ((map->map[player.x + 1][player.y] != '1')
		&& (map->map[player.x + 1][player.y]) != '2')
	{
		player.x += 1;
		map->map[player.x][player.y] = '2';
		error_path2(map, player);
		player.x -= 1;
	}
	if ((map->map[player.x][player.y + 1] != '1')
		&& (map->map[player.x][player.y + 1]) != '2')
	{
		player.y += 1;
		map->map[player.x][player.y] = '2';
		error_path2(map, player);
		player.y -= 1;
	}
}

void	error_path2(t_map *map, t_point	player)
{
	if ((map->map[player.x - 1][player.y] != '1')
		&& (map->map[player.x - 1][player.y]) != '2')
	{
		player.x -= 1;
		map->map[player.x][player.y] = '2';
		error_path2(map, player);
		player.x += 1;
	}
	if ((map->map[player.x][player.y - 1] != '1')
		&& (map->map[player.x][player.y - 1]) != '2')
	{
		player.y -= 1;
		map->map[player.x][player.y] = '2';
		error_path2(map, player);
		player.y += 1;
	}
	error_path2_next(map, player);
}

void	error_path(t_map *map)
{
	t_point	player;
	int		i;

	i = 0;
	while (map->map[i] != NULL)
	{
		if (ft_strchr(map->map[i], 'P') != NULL)
		{
			player.x = i;
			player.y = ft_strchr_y(map->map[i], 'P');
		}
		i++;
	}
	error_path2(map, player);
	error_path3(map);
}
