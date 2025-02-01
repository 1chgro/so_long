/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:54:42 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/01 04:40:56 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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
		|| c == 'C' || c == 'P' || c == 'N' || c == '\n');
}

void	count_enemies(t_game *game, int *count)
{
	int	x;
	int	y;

	*count = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'N')
				(*count)++;
			x++;
		}
		y++;
	}
}
