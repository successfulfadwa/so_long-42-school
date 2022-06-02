/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:10:20 by faljaoui          #+#    #+#             */
/*   Updated: 2022/06/02 15:20:02 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "getnext_line/get_next_line.h"

# define KEY_A 0
# define KEY_W 13
# define KEY_D 2
# define KEY_S 1
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 53
# define KEY_Q 12

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		xcol;
	int		ycol;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	void	*img_star;
	void	*img_enemie;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
	int		pos_enemies;
	int		loop;
}	t_game;

void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	display_moves(t_game *game);
int		ft_update2(t_game *game);
int		animation(t_game *game);
void	free_map(char **map);
void	tombstone_draw(t_game *game);
void	get_collet(t_game *game, int x, int y);
#endif