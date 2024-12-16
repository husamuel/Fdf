#include "fdf.h"

t_point *create_node(char *map_point, int i, int j) {
    t_point *point = malloc(sizeof(t_point));
    if (!point)
        return (NULL);

    point->x = j;
    point->y = i;
    point->z = ft_atoi(map_point);
    point->next = NULL;

    return (point);
}

t_point *cords_reader(t_date *info)
{
    char ***map = info->map;
    t_point *list = NULL;
    t_point *node;
    int i = 0;
    int j;

    while (i < info->height) {
        j = 0;
        while (j < info->width) {
            if (map[i] && map[i][j]) {
                printf("Lendo a coordenada [%d][%d]: %s\n", i, j, map[i][j]);
                node = create_node(map[i][j], i, j);
                if (!node) {
                    fprintf(stderr, "Erro: Falha ao criar o nó para a posição [%d][%d]\n", i, j);
                    break;
                }
                ft_point_add_back(&list, node);
            } else {
                fprintf(stderr, "Erro: Posição inválida no mapa em [%d][%d]\n", i, j);
                break;
            }
            j++;
        }
        i++;
    }

    return (list);
}


t_point *isometric(t_date *info)
{
    t_point *head;
    t_point *list;

    list = cords_reader(info);
    head = list;

    while (head) {
        head->x_pixel = (WIDTH / 2) + ((head->x - head->y) * cos(PI / 6));
        head->y_pixel = (HEIGHT / 2) - (head->z * sin(PI / 6)) + ((head->x + head->y) * sin(PI / 6));
        head = head->next;
    }
    return (list);
}