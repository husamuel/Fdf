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

void window(t_date *info, t_point **list)
{
    info->mlx = mlx_init();
    if (info->mlx == NULL)
		exit(1);
    info->win = mlx_new_window(info->mlx, 1920, 1080, "FDF");
    info->img = mlx_new_image(info->mlx, 1920, 1080);
	info->img_string = mlx_get_data_addr(info->img, &(info->bits), &(info->lsize), &(info->endian));
	mlx_hook(info->win, 2, 1, key_pressed, info);
	mlx_hook(info->win, 17, 0, window_close, info);
	draw_lines(info, list);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
    mlx_loop(info->mlx);
    return ;
}

void	draw_point(t_date *info, int x, int y, t_point *point)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (point->color == 0)
		{
			my_mlx_pixel_put(info, x, y, 0xFFFFFF);
		}
		else
		{
			my_mlx_pixel_put(info, x, y, point->color);
		}
	}
	return ;
}

void draw_lines(t_date *info, t_point **list)
{
    t_point *point;

    if (!list || !*list) {
        return;
    }

    point = *list;
    while (point)
    {
        if (point->point_right) {
            bresenham(info, point, point->point_right);
        }
        if (point->point_down) {
            bresenham(info, point, point->point_down);
        }
        point = point->next;
    }
}
