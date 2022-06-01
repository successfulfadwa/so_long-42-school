#include"so_long.h"
void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win,  10, game->map_h-30, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 90, game->map_h-30, 0xFFFFFF, str);
	free(str);
}
