/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:39:18 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 10:26:21 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_the_map(char *file_name, t_point **head)
{
	int	fd;
	char	*help_line;
	char	**map;
	int		rows;
	int		columns;

	rows = 0;
	columns = 0;
	fd = open(file_name, O_RDONLY);
	if(fd == -1)
		exit (0);
	while ((help_line = get_next_line(fd)) != NULL)
	{
		map = ft_split(help_line, ' ');
		while (map[rows])
		{
			create_node(head, rows, columns, map[rows]);
			rows++;			
		}
		rows = 0;
		columns = increment_and_free(columns, help_line, map);
	}
	return (0);
}

static int	check_the_extension(char *name_of_map)
{
	int	len;

	len = strlen(name_of_map);
	if (len < 4)
	{
		ft_printf("\033[1;41mmap name is very short!\033[0m\n");
		return (0);
	}
	if (strncmp(name_of_map + len - 4, ".fdf", 4) == 0)
	{
		return (0);
	}
	ft_printf("\033[1;41mNot a valid .fdf extension\033[0m\n");
	return (1);
}

int	main(int ac, char **av)
{
	t_point *head;
	t_date	info_map;
	
	head = NULL;
	if (ac != 2)
		return (ft_printf("Wrong number of arguments\n"));

	info_map.width = DEFAULT_WIDTH;
	info_map.height = DEFAULT_HEIGHT;
	if (check_the_extension(av[1]) || check_the_map(av[1], &head))
		exit(0);
	info_map.map_name = av[1];
	check_and_count(head, &info_map);
	new_windows(&info_map, &head);
	return (0);
}