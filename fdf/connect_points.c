#include "fdf.h"

void	update_point_connect(t_point *point, t_point *right, t_point *down)
{
	if (right != NULL)
		point->point_right = right;
	if (down != NULL)
		point->point_down = down;
}

t_point	*address_finder(int cord_x, int cord_y, t_point **list)
{
	t_point	*point;

	point = *list;
	while (point)
	{
		if (point->x == cord_x && point->y == cord_y)
			return (point);
		point = point->next;
	}
	return (NULL);
}

int	point_connect(t_point **list)
{
	t_point	*point;
	t_point	*tmp;

	point = *list;
	while (point != NULL)
	{
		tmp = address_finder(point->x + 1, point->y, list);
		update_point_connect(point, tmp, NULL);
		tmp = address_finder(point->x, point->y + 1, list);
		update_point_connect(point, NULL, tmp);
		point = point->next;
	}
	return (0);
}
