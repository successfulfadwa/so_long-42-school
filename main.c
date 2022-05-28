#include "so_long.h"
#include <math.h>
// #include <mlx.h>
#include<stdio.h>
// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }
// int paint(void *mlx, void *win, int X, int Y, int color)
// {
//     int i =0;
//     int j=0;
// while(j<Y)
// {
//     mlx_pixel_put(mlx,win,i,j,color);
// 	while(i<X )
//     {
//         mlx_pixel_put(mlx,win,i,j,color);
//         i++;
//     }
//     i=0;
//     j++;
// }
// return(0);
// }
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *fa)
{
	void	*img;
		int		img_width;
	int		img_height;
	
	char	*relative_path = "./unicorn.xpm";
	if (keycode==124)
	{
	
	img = mlx_xpm_file_to_image(fa->mlx, relative_path, &img_width, &img_height);
              mlx_put_image_to_window(fa->mlx, fa->win, img,800, 500);
	//  mlx_string_put(fa->mlx,fa->win,1,9,0xFFB6C1,"you did it <3");
	printf("Key pressed -> %d\n", keycode );
	}
	return (0);
}

int main()
{
	t_vars fa;
    fa.mlx = mlx_init();
	  fa.win = mlx_new_window(fa.mlx, 1920 , 1080 , "PAINT MYunicornin xpm HEHE <3");
	  mlx_key_hook(fa.win, key_hook, &fa);
    // paint(mlx, win, 1920,1080, create_trgb(100,0,45,255));
//	 mlx_string_put ( mlx,win,900, 1080/2, 800000 ,"good job <3 ");

			     mlx_loop(fa.mlx);
}