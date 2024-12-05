/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:28 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 11:55:07 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	update_point_connect(t_point *current, t_point *right, t_point *down)
{
	if (right != NULL)
		current->go_right = right;
	if (down != NULL)
		current->go_down = down;
}

static t_point	*address_finder(int cord_x, int cord_y, t_point **head)
{
	t_point *current;

	current = *head;
	while (current)
	{
		if (current->x_map == cord_x && current->y_map == cord_y)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int	point_connect(t_point **head)
{
	t_point	*current;
	t_point	*tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = address_finder(current->x_map + 1, current->y_map, head);
		update_point_connect(current, tmp, NULL);
		tmp = address_finder(current->x_map, current->y_map + 1, head);
		update_point_connect(current, NULL, tmp);
		current = current->next;
	}
	return (0);
}