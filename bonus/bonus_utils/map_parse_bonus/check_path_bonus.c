/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:55:39 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/02 16:49:54 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	check_path(t_map *map)
{
	char	**temp_grid;
	int		result;

	temp_grid = create_temp_grid(map);
	if (!temp_grid)
	{
		free_map(map);
		return (0);
	}
	copy_grid(temp_grid, map);
	flood_fill(temp_grid, map->player_position.x, map->player_position.y, map);
	result = check_reach(temp_grid, map);
	free_temp_grid(temp_grid, map);
	return (result);
}
