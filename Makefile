# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clara <clara@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 12:00:49 by chugot            #+#    #+#              #
#    Updated: 2023/07/12 20:11:21 by clara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

SRCS =	so_long.c \
		so_long_initialisation.c \
		so_long_map.c \
		so_long_error_map.c \
		so_long_error_map_bis.c \
		get_next_line.c \
		so_long_utils.c \
		so_long_utils_bis.c \
		so_long_display.c \
		so_long_display_bis.c \
		so_long_display_bis_two.c \
		so_long_display_anim.c \
		so_long_player_moves.c \
		so_long_player_moves_bis.c \
		so_long_ends.c \
		so_long_distroy.c \

CC = cc

FLAGS = -g -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

MLX_LIB	= ./minilibx-linux/libmlx.a

MLX_FLAG =	-lX11 -lXext

MLX_EX =	$(MLX_LIB) $(MLX_FLAG)


all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC)  $(FLAGS) $(OBJS) $(MLX_EX) -o $(NAME)
clean:
		rm -f $(OBJS)

fclean:
		rm -f $(OBJS) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re
