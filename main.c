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
int main()
{
	void	*img;
		int		img_width;
	int		img_height;
	img_height=100;
	img_width=50;
	char	*relative_path = "./unicorn.xpm";
    void *mlx = mlx_init();
   void *win = mlx_new_window(mlx, 1920 , 1080 , "PAINT MYunicornin xpm HEHE <3");
    // paint(mlx, win, 1920,1080, create_trgb(100,0,45,255));
//	 mlx_string_put ( mlx,win,900, 1080/2, 800000 ,"good job <3 ");

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
              mlx_put_image_to_window(mlx, win, img,800, 500);


    mlx_loop(mlx);

}