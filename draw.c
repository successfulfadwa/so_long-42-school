/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:50:27 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/02 07:25:18 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 32, y * 32);
}

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_draw(game, image, x, y);
}

static void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_colect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "door_open32.xpm", &game->img_w, &game->img_h);
	}
	img_draw(game, game->img_exit, x, y);
}

int	ft_update2 (t_game *game)
{
	// a static that saves how many frames have passed
	static int	frame;
	static int	i;
	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame  % 4273  == 0 && game->n_colect != 0)
	{
		if (i == 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_star ,game->xcol * 32, game->ycol * 32);
			i = 1;
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_colect ,game->xcol * 32, game->ycol * 32);
			i = 0;
		}
	}
	// every x*2 frames go back 
	return (0);

}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_backg, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				get_collet(game, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
	display_moves(game);
	return (0);
}
