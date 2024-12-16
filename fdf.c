#include "fdf.h"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        ft_printf("Wrong number of parameters");
    }
    t_date *info;
    t_point *list;

    info = malloc(sizeof(t_date*));
    list = malloc(sizeof(t_point *));
    info->arg_map = av[1];
    parser(info);
    list = isometric(info);
    window(info, list);
}