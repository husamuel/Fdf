#include "fdf.h"

void ft_point_add_back(t_point **list, t_point *new)
{
    t_point *tmp;

    if (!list || !new)
        return;

    if (!*list)
        *list = new;
    else
    {
        tmp = *list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}