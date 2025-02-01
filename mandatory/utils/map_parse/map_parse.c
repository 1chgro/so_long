/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:42:10 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/01 04:15:57 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map	*init_map(void)
{
	t_map	*game_map;

	game_map = malloc(sizeof(t_map));
	if (!game_map)
		return (NULL);
	game_map->grid = NULL;
	game_map->players = 0;
	game_map->exits = 0;
	game_map->collectibles = 0;
	game_map->width = 0;
	game_map->height = 0;
	return (game_map);
}

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		perror("Error\nusage: ./so_long <map_path> \t");
		return (0);
	}
	if (!valid_file_format(av[1]))
	{
		perror("Error\ninvalid file type \t");
		return (0);
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

int	validate_map_components(t_map *game_map)
{
	if (game_map->players != 1 || game_map->exits != 1)
	{
		perror("Error\nMap must have one player (P) and one exit (E)");
		return (0);
	}
	if (game_map->collectibles < 1)
	{
		perror("Error\nMap must have at least one collectible (C)");
		return (0);
	}
	if (!check_walls(game_map))
	{
		perror("Error\nMap must be surrounded by walls (1)");
		return (0);
	}
	return (1);
}

t_map	*parse_map(int ac, char **av)
{
	t_map	*game_map;

	if (!validate_args(ac, av))
		return (NULL);
	game_map = init_map();
	if (!game_map)
		return (NULL);
	if (!get_map_width_height(game_map, av[1]))
	{
		free_map(game_map);
		return (NULL);
	}
	if (!map_grid_fill(game_map, av[1]))
		return (free_map(game_map), NULL);
	if (!validate_map_components(game_map))
	{
		free_map(game_map);
		return (NULL);
	}
	return (game_map);
}
