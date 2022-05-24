#include "so_long.h"
#include <math.h>
// #include <mlx.h>
int paint(void *mlx, void *win, int X, int Y, int color)
{
    int i =0;
    int j=0;
while(j<Y)
{
    mlx_pixel_put(mlx,win,i,j,color);
	while(i<X )
    {
        mlx_pixel_put(mlx,win,i,j,color);
        i++;
    }
    i=0;
    j++;
}
return(0);
}
int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1920 , 1080 , "PAINT MY BOARD WINDOW IN PINK HEHE <3");
    paint(mlx, win, 1920,1080, 0xFFB6C1);
	 mlx_string_put ( mlx,win,900, 1080/2, 0xE75480 ,"good job <3 ");

    mlx_loop(mlx);

}