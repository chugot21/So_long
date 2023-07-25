/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:07:13 by chugot            #+#    #+#             */
/*   Updated: 2023/07/20 01:24:04 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**map;
	char	**goodmap;
	int		countline;
	int		countchar;
}	t_map;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_game
{
	int			x_slime;
	int			x_enemy;
	int			x_portal;
	int			flag_kill;
	int			count_slimes;
	int			total_slimes;
	int			moves;
	int			clock_begin;
	void		*img_0;
	void		*img_1;
	void		**tabimge;
	void		*img_e;
	void		*img_e1;
	void		*img_e2;
	void		*img_e3;
	void		*img_rip;
	void		**tabimgc;
	void		*img_c;
	void		*img_c1;
	void		*img_c2;
	void		*img_c3;
	void		*img_c4;
	void		*img_c5;
	void		**tabimgx;
	void		*img_x;
	void		*img_x1;
	void		*img_x2;
	void		*img_x3;
	void		*img_x4;
	void		*img_x5;
	void		*img_p1;
	void		*img_p2;
	void		*img_p3;
	void		*img_p4;
	void		*img_p1a;
	void		*img_p2a;
	void		*img_p3a;
	void		*img_p4a;
	int			thread;
	t_window	window;
	t_point		player;
	t_map		map;
}	t_game;

char	**ft_map(t_map *map, int fd, int fd1, int fd2);
void	treat_map(char **argv, t_map *map);
int		find_p(t_game *game);
void	find_c(t_game *game);
void	initialisations(t_game *game);
void	ft_map_copy(t_map *map);
char	*get_next_line(int fd);

void	error_map(t_map *map);
void	error_path(t_map *map);
void	error_path2(t_map *map, t_point player);
void	error_path2_next(t_map *map, t_point player);
void	error_path3(t_map *map);
void	error_wall(t_map *map);
void	error_wall_2(t_map *map, int i, int j);
void	error_rectangle(t_map *map);
void	error_items(t_map *map);
void	error_position(t_map *map);
void	error_exit(t_map *map);
void	error_rectangle(t_map *map);

void	display_map(t_game *game);
void	display_background(t_game *game);
void	display_one(t_game *game);
void	display_e(t_game *game);
void	display_x(t_game *game);
void	display_p(t_game *game);
void	display_c(t_game *game);
void	display_e_anim(t_game *game);
void	display_c_anim(t_game *game);
void	display_x_anim(t_game *game);

void	distroy_all(t_game *game);
void	destroy_enemy(t_game *game);
void	destroy_enemy_second(t_game *game);
void	destroy_enemy_next(t_game *game);
int		closew(t_game *game);
void	end_enemy(t_game *game);
void	end_win(t_game *game);

void	count_slimes(t_game *game);
int		move_player(int keycode, t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
int		ft_strchr_y(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#endif
