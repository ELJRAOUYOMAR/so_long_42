#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;
} t_data;

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
    {
        mlx_destroy_image(data->mlx, data->win);
        exit(0);
    }
    return 0;
}

int main()
{
    t_data data;

    // inintialize MLX
    data.mlx = mlx_init();
    if (!data.mlx) return 1;

    // load an image(ensure you have )
}
