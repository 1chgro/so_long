/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:43:20 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/25 08:35:38 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
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

int	get_map_width_height(t_map *game_map, char *map_file)
{
	char	*line;
	int		height;
	int		line_fd;

	line_fd = open(map_file, O_RDONLY);
	if (line_fd < 0)
		return (perror("Error\nCannot open file!"), 0);
	line = get_next_line(line_fd);
	if (!line)
		return (close(line_fd), perror("Error\nEmpty map file"), 0);
	game_map->width = map_line_width(line);
	height = 1;
	free(line);
	line = get_next_line(line_fd);
	while (line != NULL)
	{
		if (map_line_width(line) != game_map->width)
			return (free(line),
				close(line_fd), perror("Error\nMap must be rectangular"), 0);
		height++;
		free(line);
		line = get_next_line(line_fd);
	}
	return (close(line_fd), game_map->height = height, 1);
}

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

int	map_grid_fill(t_map *game_map, char *map_file)
{
	int	map_fd;
	int	y;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (perror("Error\nCould not open map file"), 0);
	game_map->grid = malloc(sizeof(char *) * game_map->height);
	if (!game_map->grid)
		return (close(map_fd), perror("Error\nMemory allocation failed"), 0);
	y = 0;
	while (y < game_map->height)
	{
		game_map->grid[y] = get_next_line(map_fd);
		if (!game_map->grid[y]
			|| !check_map_line(game_map, game_map->grid[y], y))
		{
			close(map_fd);
			return (0);
		}
		y++;
	}
	close(map_fd);
	return (1);
}
