/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:52:32 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 11:12:26 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_to_isometric_pixel(t_date *info, t_point **head)
{
	t_point *current;

	current = *head;
	while (current != NULL)
	{
		current->x_pixel = (info->center_x) + ((current->x_map - current->y_map) * cos(PI / 6) * info->scaling);

		current->y_pixel = (info->center_y) - (current->z_map * sin(PI / 6) * info->scaling) 
                 + ((current->x_map + current->y_map) * sin(PI / 6) * info->scaling);
		current = current->next;
	}
}

void	draw_lines(t_date *info, t_point **head)
{
	t_point *current;
	current = *head;
	while (current)
	{
		if(current->go_right)
			bresenham(info, current, current->go_right);
		if (current->go_down)
			bresenham(info, current, current->go_down);
		current = current->next;
	}
}

void	my_mlx_pixel_put(t_date *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_string + (y * data->lsize + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}
