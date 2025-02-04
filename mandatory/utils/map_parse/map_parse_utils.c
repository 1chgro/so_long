/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:54:42 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/02 16:33:22 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			map->grid[i] = NULL;
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	free(map);
	map = NULL;
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_file_format(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strcmp(file_name + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	map_line_width(char *line)
{
	int	width;

	width = 0;
	if (!line)
		return (0);
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'E'
		|| c == 'C' || c == 'P' || c == '\n');
}
