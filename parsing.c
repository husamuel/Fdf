#include "fdf.h"

int count_columns(char *line) {
    char **split_line;
    int count;
    int i = 0;

    if (!line)
        return (0);

    split_line = ft_split(line, ' ');

    count = 0;
    while (split_line[count])
        count++;

    while (split_line[i])
    {
        free(split_line[i]);
        i++;
    }
    free(split_line);

    return (count);
}

int count_rows(char *path) {
    int fd;
    char *line;
    int count;
    
    fd = open(path, O_RDONLY);
    if(fd < 0)
        return (-1);
    
    count = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        count++;
        free(line);
    }
    
    close(fd);
    return (count);
}

void parser(t_date *info)
{
    int fd;
    char ***map;
    char *line;
    int i;

    fd = open(info->arg_map, O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    info->height = count_rows(info->arg_map);

    map = malloc((info->height + 1) * sizeof(char **));  // +1 para o NULL no final
    if (!map) {
        perror("Erro de alocação de memória para o mapa");
        close(fd);
        return;
    }

    line = get_next_line(fd);
    if (line) {
        info->width = count_columns(line);
        free(line);
    }

    i = 0;
    while ((line = get_next_line(fd)) != NULL) {
        map[i] = ft_split(line, ' ');  // Aqui você divide a linha
        free(line);

        if (!map[i]) {
            perror("Falha ao dividir a linha");
            break;
        }

        // Garantir que cada linha termine com NULL
        int j = 0;
        while (map[i][j] != NULL) {
            j++;
        }
        map[i][j] = NULL;  // Terminar a linha com NULL

        i++;
    }

    map[i] = NULL;  // Aqui garantimos que o final do mapa é NULL

    info->map = map;
    close(fd);
}