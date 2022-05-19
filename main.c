#include "so_long.h"
// #include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;



	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 50000 , 1080 ,"mlx 77" );
	mlx_loop(mlx_ptr);

	return (0);

}