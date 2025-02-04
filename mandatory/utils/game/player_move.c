/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:12:13 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/02 16:36:21 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	initialize_exit_pos(t_game *game)
{
	int	x;
	int	y;

	if (game->exit_x != -1 && game->exit_y != -1)
		return ;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	update_grid(t_game *game, int new_x, int new_y)
{
	if (game->map->player_position.x == game->exit_x
		&& game->map->player_position.y == game->exit_y)
		game->map->grid[game->exit_y][game->exit_x] = 'E';
	else
		game->map->grid[game->map->player_position.y]
		[game->map->player_position.x] = '0';
	if (game->map->grid[new_y][new_x] == '0')
		game->map->grid[new_y][new_x] = 'P';
	else if (game->map->grid[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map->grid[new_y][new_x] = 'P';
	}
}

void	check_exit(t_game *game, int new_x, int new_y)
{
	if (new_x == game->exit_x && new_y == game->exit_y
		&& game->collected == game->map->collectibles)
	{
		ft_putendl_fd("YOU WIN 🏆", 1);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
}

int	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_position.x + dx;
	new_y = game->map->player_position.y + dy;
	initialize_exit_pos(game);
	if (game->map->grid[new_y][new_x] == '1')
		return (0);
	update_grid(game, new_x, new_y);
	check_exit(game, new_x, new_y);
	game->map->player_position.x = new_x;
	game->map->player_position.y = new_y;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	render_map(game);
	return (1);
}
