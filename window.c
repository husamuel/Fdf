#include "fdf.h"

int	key_pressed(int keycode, void *param)
{
	t_date	*info;

	info = (t_date *) param;
	if (keycode == 65307 || keycode == 113)
    {
        mlx_destroy_window(info->mlx, info->win);
        mlx_destroy_image(info->mlx, info->img);
        mlx_loop_end(info->mlx);
        exit(0);
    }
	return (1);
}

int	window_close(void *param)
{
	t_date	*info;

	info = (t_date *)param;
	mlx_destroy_window(info->mlx, info->win);
    mlx_destroy_image(info->mlx, info->img);
    mlx_loop_end(info->mlx);
    exit(0);
	return (0);
}

void window(t_date *info, t_point *list)
{
    info->mlx = mlx_init();
    if (info->mlx == NULL)
		exit(0);
    ft_printf("Map width %d\n", info->width);
    ft_printf("Map height %d", info->height);
    info->win = mlx_new_window(info->mlx, 1920, 1080, "FDF");
    info->img = mlx_new_image(info->mlx, 1920, 1080);
	mlx_hook(info->win, 2, 1, key_pressed, info);
	mlx_hook(info->win, 17, 0, window_close, info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
    put_pixels(info, list);
    mlx_loop(info->mlx);
    return ;
}

void put_pixels(t_date *info, t_point *list)
{
    t_point *head;

    head = list;
    while(head)
    {
        mlx_pixel_put(info->mlx, info->win, head->x_pixel, head->y_pixel, 0xFFFFFF);
        head = head->next;
    }
}