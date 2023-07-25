/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display_anim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:58:55 by chugot            #+#    #+#             */
/*   Updated: 2023/07/24 20:58:57 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_x_anim(t_game *game)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	i = 0;
	j = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'X')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->tabimgx[game->x_enemy], img_width * j,
					img_height * i);
			if (game->x_enemy == 5)
				game->x_enemy = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_enemy++;
}

void	display_c_anim(t_game *game)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	i = 0;
	j = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'C')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->tabimgc[game->x_slime], img_width * j,
					img_height * i);
			if (game->x_slime == 5)
				game->x_slime = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_slime++;
}

void	display_e_anim(t_game *game)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	i = 0;
	j = 0;
	while (game->map.goodmap[i] != NULL)
	{
		while (game->map.goodmap[i][j] != '\n')
		{
			if (game->map.goodmap[i][j] == 'E')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->tabimge[game->x_portal], img_width * j,
					img_height * i);
			if (game->x_portal == 3)
				game->x_portal = 0;
			j++;
		}
		j = 0;
		i++;
	}
	game->x_portal++;
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*dest;

	dest = (char *) s;
	i = 0;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (s);
}
