#ifndef FDF_H
#define FDF_H

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
}   t_date;

typedef struct s_point
{
    int x_pixel;
    int y_pixel;
    int x;
    int y;
    int z;
    struct s_point *next;
}   t_point;

# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265358979323846

int count_rows(char *path);
int count_columns(char *line);
void parser(t_date *info);

void window(t_date *info, t_point *list);
void put_pixels(t_date *info, t_point *list);

t_point *create_node(char *map_point, int i, int j);
t_point *cords_reader(t_date *info);
t_point *isometric(t_date *info);

void ft_point_add_back(t_point **list, t_point *new);

#endif
