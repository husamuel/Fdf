/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:23:38 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 11:24:45 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info_to_list(t_date *info, t_point **head)
{
	t_point	*tmp;

	tmp = *head;
	while (tmp)
	{
		tmp->infra = info;
		tmp = tmp->next;
	}
}