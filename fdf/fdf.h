#ifndef FDF_H
#define FDF_H

# include "minilibx-linux/minilibx-linux/mlx.h"
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
#include <stddef.h>

typedef struct s_date
{
    void *mlx;
    void *win;
    void *img;
    int width;
    int height;
    char ***map;
    char *arg_map;
	char *img_string;
	double	scaling;
	double 	center_x;
	double	center_y;
	int			bits;
	int			lsize;
	int			endian;
}   t_date;

typedef struct s_point
{
    int x_pixel;
    int y_pixel;
    int x;
    int y;
    int z;
	unsigned int color;
	struct s_point	*point_right;
	struct s_point	*point_down;
    struct s_point *next;
}   t_point;

# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265358979323846
//parsing.c
int count_rows(char *path);
int count_columns(char *line);
void parser(t_date *info);
//window.c
void window(t_date *info, t_point **list);
int	key_pressed(int keycode, void *param);
int	window_close(void *param);
void	draw_point(t_date *info, int x, int y, t_point *point);
void	draw_lines(t_date *info, t_point **list);
//isometric
t_point *create_node(char *map_point, int i, int j);
t_point **cords_reader(t_date *info);
t_point **isometric(t_date *info);
void	my_mlx_pixel_put(t_date *info, int x, int y, int color);
//utils.c
void ft_point_add_back(t_point **list, t_point *new);
void	scale(t_date *info);
//bresenham.c
int	calculate_step(int start, int end);
void	incline_x(int delta_x, int delta_y, t_point *start, t_point *end, t_date *info);
void	incline_y(int delta_x, int delta_y, t_point *start, t_point *end, t_date *info);
void	bresenham(t_date *info, t_point *start, t_point *end);
//connect_points.c
void	update_point_connect(t_point *point, t_point *right, t_point *down);
t_point	*address_finder(int cord_x, int cord_y, t_point **list);
int	point_connect(t_point **list);
//color
int	check_commas(char *str, t_point *new_node);
int	color_zed(char *input, t_point *new_node);
#endif
