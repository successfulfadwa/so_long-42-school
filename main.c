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

int	key_hook(int keycode, t_vars *vars)
{
	// void *img;
	// char *imgpath="./bigkissuniS.xpm";
	// int width;
	// int height;
	

	// img =mlx_xpm_to_image(vars->mlx,&imgpath, &width, &height);
	if (keycode==124)
	{
	// mlx_put_image_to_window(vars->mlx,vars->win,img,1,2);
	 mlx_string_put(vars->mlx,vars->win,1,9,0xFFB6C1,"you did it <3");
	printf("Key pressed -> %d\n", keycode );
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
