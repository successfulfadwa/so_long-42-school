#include "so_long.h"
// #include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;



	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920 , 1080 ,"mlx 77" );
	mlx_pixel_put  ( mlx_ptr,win_ptr,1920/2, 1080/2, 0xFFB6C1 );
	 mlx_string_put ( mlx_ptr,win_ptr,1920/2, 1080/2, 0xFFB6C1 ,"fadwa1337");
	mlx_loop(mlx_ptr);
	return (0);

}
