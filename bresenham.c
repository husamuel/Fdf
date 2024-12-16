#include "fdf.h"

int	calculate_step(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

void	incline_x(int delta_x, int delta_y, t_point *start, t_point *end, t_date *info)
{
	int	step_x;
	int	step_y;
	int	x;
	int	y;
	int	p;

	x = start->x_pixel;
	y = start->y_pixel;
	p = delta_y - delta_x / 2;
	step_x = calculate_step(start->x_pixel, end->x_pixel);
	step_y = calculate_step(start->y_pixel, end->y_pixel);
	while (x != end->x_pixel)
	{
		draw_point(info, x, y, start);
		x += step_x;
		if (p >= 0)
		{
			y += step_y;
			p -= delta_x;
		}
		p += delta_y;
	}
}

void	incline_y(int delta_x, int delta_y, t_point *start, t_point *end, t_date *info)
{
	int	step_x;
	int	step_y;
	int	x;
	int	y;
	int	p;

	x = start->x_pixel;
	y = start->y_pixel;
	p = delta_x - delta_y / 2;
	step_x = calculate_step(start->x_pixel, end->x_pixel);
	step_y = calculate_step(start->y_pixel, end->y_pixel);
	while (y != end->y_pixel)
	{
		draw_point(info, x, y, start);
		y += step_y;
		if (p >= 0)
		{
			x += step_x;
			p -= delta_y;
		}
		p += delta_x;

	}
}

void	bresenham(t_date *info, t_point *start, t_point *end)
{
	int	delta_x;
	int	delta_y;

	delta_x = abs(end->x_pixel - start->x_pixel);
	delta_y = abs(end->y_pixel - start->y_pixel);
	if (delta_x >= delta_y)
	{
		incline_x(delta_x, delta_y, start, end, info);
	}
	else
	{
		incline_y(delta_x, delta_y, start, end, info);
	}
	draw_point(info, end->x_pixel, end->y_pixel, end);
}