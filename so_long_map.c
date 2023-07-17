 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:08:43 by chugot            #+#    #+#             */
/*   Updated: 2023/06/29 18:08:44 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**malloc_tab_map(t_map *map, int fd1)
{
	char *line;

	map->countline = 0;
	line = get_next_line(fd1);
	while (line)
	{
		line = get_next_line(fd1);
		map->countline++;
	}
	map->map = malloc(sizeof(char *) * (map->countline + 1));
	if (!map->map)
		exit (0);
	return (map->map);
}

void	malloc_line_map(t_map *map, int fd2)
{
	char	*line;
	int	i;

	i = 0;
    line = get_next_line(fd2);
	while (line)
	{
		map->map[i] = line;
		line = get_next_line(fd2);
		i++;
	}
}

char	**write_map(t_map *map, int fd)
{
	int	i;

	i = 0;
	map->map[map->countline] = NULL;
	map->map[i] = get_next_line(fd);
	while (map->map[i] != NULL)
	{
		i++;
		map->map[i] = get_next_line(fd);
	}
	return (map->map);
}

char	**ft_map(t_map *map, int fd, int fd1, int fd2)
{
	int	i;

	i = 0;
	map->map = malloc_tab_map(map, fd1);
	malloc_line_map(map, fd2);
	map->map = write_map(map, fd);
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	return (map->map);
}

void	ft_map_copy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->goodmap = malloc(sizeof(char *) * (map->countline + 1));
	if (!map->goodmap)
		exit (0);
	while (map->map[i] != NULL)
	{
		map->goodmap[i] = malloc(sizeof(char) * (map->countchar + 1));
		if (!map->goodmap[i])
			exit (0);
		i++;
	}
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