/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:08:25 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/02 18:02:01 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	init_enemies(t_game *game)
{
	int	count;

	count_enemies(game, &count);
	game->enemy_count = count;
	game->enemies = malloc(sizeof(t_enemy) * count);
	if (!game->enemies)
		return ;
	init_enemy_positions(game);
}

void	movement_direction(t_game *game, t_enemy *enemy, int *dx, int *dy)
{
	int	diff_x;
	int	diff_y;
	int	player_x;
	int	player_y;

	player_x = game->map->player_position.x;
	player_y = game->map->player_position.y;
	diff_x = player_x - enemy->x;
	diff_y = player_y - enemy->y;
	if (abs(diff_x) > abs(diff_y))
	{
		if (diff_x > 0)
			*dx = 1;
		else
			*dx = -1;
		*dy = 0;
	}
	else
	{
		*dx = 0;
		if (diff_y > 0)
			*dy = 1;
		else
			*dy = -1;
	}
}

void	enemy_movement(t_game *game, t_enemy *enemy, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	current_cell;

	new_x = enemy->x + dx;
	new_y = enemy->y + dy;
	if (new_x >= 0 && new_x < game->map->width && new_y >= 0
		&& new_y < game->map->height
		&& game->map->grid[new_y][new_x] != '1'
		&& game->map->grid[new_y][new_x] != 'N'
		&& game->map->grid[new_y][new_x] != 'E'
		&& game->map->grid[new_y][new_x] != 'C')
	{
		current_cell = game->map->grid[new_y][new_x];
		if (game->map->grid[enemy->y][enemy->x] == 'N')
			game->map->grid[enemy->y][enemy->x] = '0';
		enemy->x = new_x;
		enemy->y = new_y;
		if (current_cell == '0')
			game->map->grid[new_y][new_x] = 'N';
		if (new_x == game->map->player_position.x
			&& new_y == game->map->player_position.y)
			game_over(game);
	}
}

void	move_enemies(t_game *game)
{
	static int	frame_counter = 0;
	int			i;
	int			dx;
	int			dy;

	i = 0;
	frame_counter++;
	if (frame_counter < 30)
		return ;
	frame_counter = 0;
	while (i < game->enemy_count)
	{
		movement_direction(game, &game->enemies[i], &dx, &dy);
		enemy_movement(game, &game->enemies[i], dx, dy);
		i++;
	}
}

int	animation_loop(t_game *game)
{
	update_coin_animation(game);
	move_enemies(game);
	render_map(game);
	moves_count(game);
	return (0);
}
