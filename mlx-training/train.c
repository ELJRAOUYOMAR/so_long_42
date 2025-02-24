#include "../minilibx-linux/mlx.h"
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

int close_window(t_data *data)
{
    // (void)param;
    mlx_destroy_window(data->mlx, data->win);
    free(data->mlx);
    exit(0); // exit the program when the window is closed.
    return 0;
}
int handle_keypress(int keycode, t_data *data)
{
    (void)data;
    if (keycode == XK_Escape)
    {
        // mlx_clear_window(data->mlx, data->win);
        // mlx_destroy_image(data->mlx, data->img);
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(0);
        return(0);
    }
    return 0;
}

int main()
{
    t_data data;

    // inintialize MLX
    data.mlx = mlx_init();
    // if the is an issue with X11
    if (!data.mlx) return 1;

    // create a window
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Just a Test");
    if (!data.win) return (free(data.win), 1);
    // load an image(ensure having the xpm file)
    data.img = mlx_xpm_file_to_image(data.mlx, "resized_test.xpm", &data.img_width, &data.img_height);
    if (!data.img)
    {
        perror("Failed to load image");
        return 1;
    }
    // Display the image in the window
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    // Handle keypress(close window on ESC)
    mlx_key_hook(data.win, handle_keypress, &data);
    // hook to close event 
    mlx_hook(data.win, 17, 0, close_window, &data); // 17 on linux: DestroyNotify in X11
    // Run the MLX event loop
    mlx_loop(data.mlx);
    return(0);
}
