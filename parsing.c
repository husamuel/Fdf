/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:05:55 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 11:23:23 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_list(t_point *list)
{
	t_point	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	create_node(t_point **head, int x, int y, char *z_string)
{
	t_point *new_node;
	t_point	*current;

	new_node = (t_point *)malloc(sizeof(t_point));
	if (new_node == NULL)
		exit(1);
	new_node->x_map = x;
	new_node->y_map = y;
	new_node->z_map = check_commas(z_string, new_node);
	new_node->x_pixel = 0;
	new_node->y_pixel = 0;
	new_node->go_right = NULL;
	new_node->go_down = NULL;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	free(z_string);
}

void	space_and_scale(t_date *inf)
{
	double	width_scale;
	double	hight_scale;
	double	big_line;

	big_line = sqrt(pow(inf->columns - 1, 2) + pow(inf->rows - 1, 2));
	width_scale = inf->width / big_line;
	hight_scale = inf->height / big_line;
	inf->scaling = fmin(width_scale, hight_scale);
	inf->center_x = (inf->width - (inf->scaling * (inf->columns - 1))) / 2;
	inf->center_y = (inf->height - (inf->scaling * (inf->rows - 1))) / 2;
}

void	check_and_count(t_point *head, t_date *info_map)
{
	t_point	*tmp;
	int			count;
	
	count = 0;
	tmp = head;
	while(tmp)
	{
		if (tmp->next == NULL)
		{
			info_map->columns = tmp->x_map + 1;
			info_map->rows = tmp->y_map + 1;
		}
		tmp = tmp->next;
		count++;
	}
	info_map->total_points = count;
	info_to_list(info_map, &head);
	point_connect(&head);
	space_and_scale(info_map);
	int_to_isometric_pixel(info_map, &head);
	return ;	
}
