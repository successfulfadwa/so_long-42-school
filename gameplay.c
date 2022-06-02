/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:50:40 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:38 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_collet(t_game *game, int x, int y)
{
	game->xcol = x;
	game->ycol = y;
	img_draw(game, game->img_colect, x, y);
}

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		printf("Moves: %d\n", game->moves);
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_update2, game);
	mlx_hook(game->win, 2, 0, keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 9, 0, map_draw, game);
}
