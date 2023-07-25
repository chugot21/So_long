/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:34:56 by chugot            #+#    #+#             */
/*   Updated: 2023/07/08 20:07:27 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(t_map *map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		if (ft_strchr(map->map[i], 'E') == NULL)
			i++;
		else
		{
			flag += 1;
			i++;
		}
	}
	if (flag != 1)
	{
		write(1, "Error exit\n", 11);
		exit (0);
	}
}

void	error_position(t_map *map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		if (ft_strchr(map->map[i], 'P') == NULL)
			i++;
		else
		{
			flag += 1;
			i++;
		}
	}
	if (flag != 1)
	{
		write(1, "Error start position\n", 21);
		exit (0);
	}
}

void	error_items(t_map *map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		if (ft_strchr(map->map[i], 'C') == NULL)
			i++;
		else
		{
			flag += 1;
			i++;
		}
	}
	if (flag == 0)
	{
		write(1, "Error no item\n", 14);
		exit (0);
	}
}

void	error_rectangle(t_map *map)
{
	int	i;

	i = 0;
	map->countchar = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) == map->countchar)
			i++;
		else
		{
			write(1, "Error map is not a rectangle\n", 29);
			exit (0);
		}
	}
}

void	error_wall_2(t_map *map, int i, int j)
{
	while (i != (map->countline - 1))
	{
		j = 0;
		if (map->map[i][0] != '1' || map->map[i][map->countchar - 2] != '1')
		{
			write(1, "Error map is not closed by wall\n", 31);
			exit (0);
		}
		i++;
	}
	j = 0;
	while (map->map[i][j] != '\n')
	{
		if (map->map[i][j] != '1')
		{
			write(1, "Error map is not closed by wall\n", 31);
			exit (0);
		}
		j++;
	}
}
