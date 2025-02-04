/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:23:06 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/03 00:14:18 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	win_size_check(t_map *map)
{
	if (map->height * TILE_SIZE > 1312)
	{
		free_map(map);
		perror("Error\nProblem in Window size");
		exit(1);
	}
}
