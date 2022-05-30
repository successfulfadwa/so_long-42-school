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
	int y;
	int x;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	int		img_width;
	int		img_height;
}				t_vars;

int	key_hook(int keycode, t_vars *fa)
{
	// char	*relative_path = "./unicorn.xpm";

	mlx_clear_window (fa->mlx, fa->win);
	if (keycode==124 ||keycode==2 )
	{
		
	fa->x=  fa->x+100;
	printf("Key pressed -> %d\n", keycode );
	}
	else if (keycode==123||keycode==0)
	{
	fa->x=fa->x-100;
	printf("Key pressed -> %d\n", keycode );
	}
	else if (keycode==125||keycode==1)
	{
	fa->y=fa->y+100;
	printf("Key pressed -> %d\n", keycode );
	}
	else if (keycode==126 ||keycode==13)
	{
	fa->y=fa->y-100;
	printf("Key pressed -> %d\n", keycode );
	}
	mlx_put_image_to_window(fa->mlx, fa->win, fa->img,fa->x, fa->y);
	
	mlx_put_image_to_window(fa->mlx, fa->win, fa->img2,fa->x, fa->y);
	// mlx_string_put(fa->mlx,fa->win,1,9,0xFFB6C1,"you did it <3");

	return (0);
}

int main()
{
	t_vars fa;

    fa.mlx = mlx_init();
	fa.y=0;
	fa.x=0;

	fa.win = mlx_new_window(fa.mlx, 2500 ,1377 , "PAINT MYunicornin xpm HEHE <3");
	fa.img = mlx_xpm_file_to_image(fa.mlx, "./hello2.xpm", &fa.img_width, &fa.img_height);
	fa.img2 = mlx_xpm_file_to_image(fa.mlx, "./hello1.xpm", &fa.img_width, &fa.img_height);
	mlx_put_image_to_window(fa.mlx, fa.win, fa.img,fa.x, fa.y);
	mlx_key_hook(fa.win, key_hook, &fa);
    // paint(mlx, win, 1920,1080, create_trgb(100,0,45,255));
//	 mlx_string_put ( mlx,win,900, 1080/2, 800000 ,"good job <3 ");

			     mlx_loop(fa.mlx);
}