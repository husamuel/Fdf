#include "fdf.h"

void ft_point_add_back(t_point **list, t_point *new)
{
    t_point *tmp;

    if (!list || !new)
        return;

    if (!*list)
        *list = new;
    else
    {
        tmp = *list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void	scale(t_date *info)
{
	double	width_scale;
	double	hight_scale;
	double	big_line;

	big_line = sqrt(pow(WIDTH - 1, 2) + pow(HEIGHT - 1, 2));
	width_scale = WIDTH / big_line;
	hight_scale = HEIGHT / big_line;
	info->scaling = fmin(width_scale, hight_scale);
	info->center_x = WIDTH / 2;
	info->center_y = HEIGHT / 5;
}