/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:24:54 by husamuel          #+#    #+#             */
/*   Updated: 2024/12/05 12:00:47 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	increment_and_free(int count, char *str, char **map)
{
	count++;
	free(str);
	free(map);
	return (count);
}

int	check_commas(char *str, t_point *new_node)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == ',')
			return (color_zed(str, new_node));
		new_node->color = 0;
		count++;
	}
	return (ft_atoi(str));
}

static unsigned long	ft_strtol(const char *str)
{
	const char		*hex;
	unsigned long	result;
	const char		*ptr;

	hex = "0123456789abcdef";
	result = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str != '\0')
	{
		ptr = ft_strchr(hex, *str);
		if (ptr == NULL)
			break ;
		result = result * 16 + (ptr - hex);
		str++;
	}
	return (result);
}

int	color_zed(char *input, t_point *new_node)
{
	int	i;
	int	z;
	int	color;

	i = 0;
	z = 0;
	color = 0;
	while (input[i] != ',' && input[i] != '\0')
	{
		z = (z * 10) + (input[i] - '0');
		i++;
	}
	if (input[i] == ',')
		i++;
	new_node->color = ft_strtol(&input[i]);
	return (z);
}