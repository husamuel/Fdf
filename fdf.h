/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:50:38 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 12:11:54 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MINUS 27
# define PLUS 24
# define SPACE 49
# define KEY_R 15
# define ESCAPE 53

# define DEFAULT_WIDTH 1280
# define DEFAULT_HEIGHT 720
# define MAX_WIDTH 5120
# define MAX_HEIGHT 2880

# define PI 3.14159265358979323846

typedef struct s_date
{
	char		*map_name;
	int			rows;
	int			map_width;
	int			columns;
	int			map_height;
	int			total_points;
	int			width;
	int			height;
	double		max_x;
	double		max_y;
	double		min_x;
	double		min_y;
	double		scaling;
	double		center_x;
	double		center_y;
	void		*mlx;
	void		*window;
	void		*img_pointer;
	int			bits;
	int			lsize;
	int			endian;
	char		*img_string;
}		t_date;

typedef struct s_point
{
	t_date			*infra;
	int				x_map;
	int				y_map;
	int				z_map;
	int				x_pixel;
	int				y_pixel;
	int				z_pixel;
	unsigned long	color;
	struct s_point	*go_right;
	struct s_point	*go_down;
	struct s_point	*next;
}		t_point;

void	create_node(t_point **head, int x, int y, char *z_string);
/* function to print and debug */
void	print_colored_list(t_point **head);
void	print_infos(t_date *info);
/* Perform operation on the list */
void	check_and_count(t_point *head, t_date *info_map);
int		point_connect(t_point **head);
void	info_to_list(t_date *info, t_point **head);
void	connect_down_nodes(t_point *current);
/* Encapsulation the  mlx function */
void	new_windows(t_date *mac, t_point **head);
void	new_image(t_date *inf);
void	clean_close(t_date *project);
/* scaling and changing  the pixel coordinates*/
void	space_and_scale(t_date *info);
void	int_to_pixel(t_date *info, t_point **head);
void	int_to_isometric_pixel(t_date *info, t_point **head);
/*Adding the function to draw in the image*/
void	bresenham(t_date *info, t_point *start, t_point *end);
void	draw_point(t_date *info, int x, int y, t_point *point);
void	draw_lines(t_date *info, t_point **head);
/* using other function too*/
void	ft_draw_instructions(t_date *env);
int		key_pressed(int keycode, void *param);
void	test_function(t_date *env);
/* thanks to 42 Docs*/
void	my_mlx_pixel_put(t_date *date, int x, int y, int color);
void	isometric(t_date *info, t_point **head);
/* check for the commas*/
int		check_commas(char *str, t_point *new_node);
int		color_zed(char *input, t_point *new_node);
/* check for the windows size */
void	check_if_windows(t_date *info_map);
/* increment  counter and freeing stuff */
int		increment_and_free(int count, char *str, char **matrix);
int		this_free(char *string);
int		free_split(char **tab);
void	free_list(t_point *list);

#endif
