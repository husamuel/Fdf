/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:07:08 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 11:26:03 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_pressed(int keycode, void *param)
{
	t_date	*help;

	help = (t_date *) param;
	if (keycode == ESCAPE)
	mlx_destroy_window(help->mlx, help->window);
	return (1);
}

int	window_close(void *param)
{
	t_date	*help;

	help = (t_date *)param;
	mlx_destroy_window(help->mlx, help->window);
	return (0);
}

void	new_windows(t_date *help, t_point **head)
{
	help->mlx = mlx_init();
	if (help->mlx == NULL)
		exit(0);
	help->window = mlx_new_window(help->mlx, help->width, help->height, help->map_name);
	help->img_pointer = mlx_new_image(help->mlx, help->width,
			help->height);
	help->img_string = mlx_get_data_addr(help->img_pointer, &(help->bits),
			&(help->lsize), &(help->endian));
	mlx_hook(help->window, 2, 1, key_pressed, help);
	mlx_hook(help->window, 17, 0, window_close, help);
	draw_lines(help, head);
	mlx_put_image_to_window(help->mlx, help->window, help->img_pointer, 0, 0);	
	mlx_string_put(help->mlx, help->window, 540, 0, 0xFF0000, "atucci FDF, no bonus :(");
	free_list(*head);
	mlx_loop(help->mlx);
	return ;
}