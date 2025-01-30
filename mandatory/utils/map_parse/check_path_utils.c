/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:58:15 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/27 01:04:16 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	flood_fill(char **temp_grid, int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height
		|| temp_grid[y][x] == '1' || temp_grid[y][x] == 'F')
		return ;
	temp_grid[y][x] = 'F';
	flood_fill(temp_grid, x + 1, y, map);
	flood_fill(temp_grid, x - 1, y, map);
	flood_fill(temp_grid, x, y + 1, map);
	flood_fill(temp_grid, x, y - 1, map);
}

char	**create_temp_grid(t_map *map)
{
	char	**temp_grid;
	int		i;

	temp_grid = (char **)malloc(sizeof(char *) * map->height);
	if (!temp_grid)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		temp_grid[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!temp_grid[i])
		{
			while (--i >= 0)
				free(temp_grid[i]);
			free(temp_grid);
			return (NULL);
		}
		i++;
	}
	return (temp_grid);
}

void	copy_grid(char **temp_grid, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			temp_grid[i][j] = map->grid[i][j];
			j++;
		}
		temp_grid[i][map->width] = '\0';
		i++;
	}
}

void	free_temp_grid(char **temp_grid, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(temp_grid[i]);
		i++;
	}
	free(temp_grid);
}

int	check_reach(char **temp_grid, t_map *map)
{
	int		i;
	int		j;
	int		collectibles_found;
	int		exit_found;

	i = 0;
	collectibles_found = 0;
	exit_found = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C' && temp_grid[i][j] == 'F')
				collectibles_found++;
			if (map->grid[i][j] == 'E' && temp_grid[i][j] == 'F')
				exit_found = 1;
			j++;
		}
		i++;
	}
	return (collectibles_found == map->collectibles && exit_found);
}
