#include "fdf.h"

t_point *create_node(char *map_point, int i, int j) {
    t_point *point = malloc(sizeof(t_point));
    if (!point)
        return (NULL);

    point->x = j;
    point->y = i;
    point->z = check_commas(map_point, point);
	point->color = 0;
	point->x_pixel = 0;
	point->y_pixel = 0;
	point->point_right = NULL;
	point->point_down = NULL;
	point->next = NULL;
    return (point);
}

t_point **cords_reader(t_date *info)
{
    char ***map = info->map;
    t_point **list = malloc(sizeof(t_point *));  // Aloca memória corretamente para a lista de pontos
    if (!list)
        return NULL;

    *list = NULL;  // Inicializa a lista como vazia

    t_point *node;
    int i = 0;
    int j;

    while (i < info->height) {
        j = 0;
        while (j < info->width) {
            if (map[i] && map[i][j]) {
                node = create_node(map[i][j], i, j);
                if (!node) {
                    fprintf(stderr, "Erro: Falha ao criar o nó para a posição [%d][%d]\n", i, j);
                    break;
                }
                ft_point_add_back(list, node);  // Adiciona o nó na lista
            } else {
                break;
            }
            j++;
        }
        i++;
    }

    return list;
}


t_point **isometric(t_date *info)
{
    t_point *head;
    t_point **list;

    list = cords_reader(info);
    if (!list || !*list)
        return NULL;

    head = *list;
    while (head) {
		printf(" %d %d %d, ", head->x, head->y, head->z);
		head->x_pixel = (info->center_x) + ((head->x - head->y) * cos(PI / 6) * info->scaling); 
		head->y_pixel = (info->center_y) - (head->z * sin(PI / 6) * info->scaling * 20) + ((head->x + head->y) * sin(PI / 6) * info->scaling);
        head = head->next;
    }
    return list;
}


void	my_mlx_pixel_put(t_date *info, int x, int y, int color)
{
	char	*dst;

	dst = info->img_string + (y * info->lsize + x * (info->bits / 8));
	*(unsigned int *)dst = color;
}