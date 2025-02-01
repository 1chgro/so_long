/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:42:35 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/01 04:43:44 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	init_coin_animation(&game);
	mlx_loop_hook(game.mlx, animation_loop, &game);
	mlx_hook(game.win, 2, 0, handle_keys, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	clean_coin_animation(&game);
	cleanup_enemies(&game);
	free(game_map);
	return (0);
}
