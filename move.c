/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:06 by faljaoui          #+#    #+#             */
/*   Updated: 2022/06/02 17:46:10 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, game->map_h - 30,
		0xFF6EC7, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 90, game->map_h - 30, 0xFF6EC7, str);
	free(str);
}

void	tombstone_draw(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_clear_window(game->mlx, game->win);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "riiip32.xpm", &game->img_w, &game->img_h);
	game->endgame = 1;
	map_draw(game);
}
