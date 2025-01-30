/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:08:28 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/30 21:42:13 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	cleanup_enemies(t_game *game)
{
	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
}

void	game_over(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putendl_fd("YOU LOSE!🤡", 1);
	clean_coin_animation(game);
	cleanup_enemies(game);
	exit(0);
}

void	init_enemy_positions(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'N')
			{
				game->enemies[count].x = x;
				game->enemies[count].y = y;
				count++;
			}
			x++;
		}
		y++;
	}
}
