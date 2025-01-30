/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:32:13 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/30 23:52:41 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_map	*game_map;

	game_map = parse_map(ac, av);
	if (!game_map)
		return (1);
	if (!check_path(game_map))
		return (perror("Error\nPlayer cannot get to the exit or collectibles"),
			1);
	if (!init_game(&game, game_map))
		return (free(game_map), 1);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keys, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free(game_map);
	return (0);
}
