/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:42:10 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/22 06:11:10 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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
		return (NULL);
	if (!validate_map_components(game_map))
	{
		free_map(game_map);
		return (NULL);
	}
	return (game_map);
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
