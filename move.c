/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:06 by faljaoui          #+#    #+#             */
/*   Updated: 2022/06/04 18:11:52 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		(game->mlx, "xpmfile/riiip32.xpm", &game->img_w, &game->img_h);
	if (!game->img_player)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	game->endgame = 1;
	map_draw(game);
}
