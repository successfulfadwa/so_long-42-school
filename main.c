#include "so_long.h"
#include <math.h>
// #include <mlx.h>
int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double LEN_X = endX - beginX; // 10
	double LEN_Y = endY - beginY;

int pixels = sqrt((LEN_X* LEN_X) + (LEN_Y * LEN_Y));

LEN_X= LEN_X/pixels; // 1
LEN_Y = LEN_Y /pixels; // 0
double pixelX = beginX;
double pixelY = beginY;
while (pixels)
{
    mlx_pixel_put(mlx, win, pixelX, pixelY, color);
    pixelX = pixelX+LEN_X;
    pixelY = pixelY+LEN_Y;
    --pixels;
}
return(0);
}
int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1920 , 1080 , "Tutorial Window - Draw Line <3");
	mlx_string_put ( mlx,win,1920/2, 1080/2, 0xFFB6C1 ,"good job <3 ");

    draw_line(mlx, win, 1920/2, 1080/2, 400, 300, 0xFFB6C1);

    mlx_loop(mlx);
}