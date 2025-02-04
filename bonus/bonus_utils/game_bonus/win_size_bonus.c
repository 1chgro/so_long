/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:22:35 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/03 00:15:31 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	win_size_check(t_map *map)
{
	if (map->height * TILE_SIZE > 1312)
	{
		free_map(map);
		perror("Error\nWindow size is huge");
		exit(1);
	}
}
