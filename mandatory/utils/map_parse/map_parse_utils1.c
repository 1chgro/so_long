/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:43:20 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/02 16:32:40 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_map_line(t_map *game_map, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (!is_valid_map_char(line[x]))
			return (perror("Error\nInvalid character in map"), 0);
		if (line[x] == 'P')
		{
			game_map->players += 1;
			game_map->player_position.x = x;
			game_map->player_position.y = y;
		}
		else if (line[x] == 'E')
			game_map->exits += 1;
		else if (line[x] == 'C')
			game_map->collectibles += 1;
		x++;
	}
	return (1);
}

int	map_grid_allocate(t_map *game_map, char *map_file)
{
	int	map_fd;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (perror("Error\nCould not open map file"), 0);
	game_map->grid = malloc(sizeof(char *) * game_map->height);
	if (!game_map->grid)
		return (close(map_fd), perror("Error\nMemory allocation failed"), 0);
	return (map_fd);
}

int	map_grid_fill_lines(t_map *game_map, int map_fd)
{
	int	y;

	y = 0;
	while (y < game_map->height)
	{
		game_map->grid[y] = get_next_line(map_fd);
		if (!game_map->grid[y]
			|| !check_map_line(game_map, game_map->grid[y], y))
		{
			while (y >= 0)
			{
				free(game_map->grid[y]);
				y--;
			}
			free(game_map->grid);
			game_map->grid = NULL;
			close(map_fd);
			return (0);
		}
		y++;
	}
	return (1);
}

int	map_grid_fill(t_map *game_map, char *map_file)
{
	int	map_fd;

	map_fd = map_grid_allocate(game_map, map_file);
	if (!map_fd)
		return (0);
	if (!map_grid_fill_lines(game_map, map_fd))
		return (0);
	close(map_fd);
	return (1);
}
