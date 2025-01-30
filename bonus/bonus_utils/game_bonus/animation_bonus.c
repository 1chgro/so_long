/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:39:38 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/30 12:28:34 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	init_coin_animation(t_game *game)
{
	int	width;
	int	height;

	game->coin_anim.current_frame = 0;
	game->coin_anim.frame_counter = 0;
	game->coin_anim.num_frames = 8;
	game->coin_anim.coins[0].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin1.xpm", &width, &height);
	game->coin_anim.coins[1].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin2.xpm", &width, &height);
	game->coin_anim.coins[2].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin3.xpm", &width, &height);
	game->coin_anim.coins[3].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin4.xpm", &width, &height);
	game->coin_anim.coins[4].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin5.xpm", &width, &height);
	game->coin_anim.coins[5].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin6.xpm", &width, &height);
	game->coin_anim.coins[6].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin7.xpm", &width, &height);
	game->coin_anim.coins[7].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/bonus_utils/sprites/coin_anim/coin8.xpm", &width, &height);
}

void	update_coin_animation(t_game *game)
{
	game->coin_anim.frame_counter++;
	if (game->coin_anim.frame_counter >= 8)
	{
		game->coin_anim.frame_counter = 0;
		game->coin_anim.current_frame++;
		if (game->coin_anim.current_frame >= game->coin_anim.num_frames)
			game->coin_anim.current_frame = 0;
	}
}

void	clean_coin_animation(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->coin_anim.num_frames)
	{
		if (game->coin_anim.coins[i].img)
		{
			mlx_destroy_image(game->mlx, game->coin_anim.coins[i].img);
			game->coin_anim.coins[i].img = NULL;
		}
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
