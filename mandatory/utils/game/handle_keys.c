/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:07:48 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/30 23:52:48 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	handle_keys(int keysym, t_game *game)
{
	if (keysym == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keysym == 13 || keysym == 126)
		move_player(game, 0, -1);
	else if (keysym == 1 || keysym == 125)
		move_player(game, 0, 1);
	else if (keysym == 0 || keysym == 123)
		move_player(game, -1, 0);
	else if (keysym == 2 || keysym == 124)
		move_player(game, 1, 0);
	return (0);
}

int	close_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
