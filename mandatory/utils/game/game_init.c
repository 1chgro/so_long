/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:02:41 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/02 16:36:45 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_images(t_game *game)
{
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->empty.img)
		mlx_destroy_image(game->mlx, game->empty.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
}

int	init_game(t_game *game, t_map *game_map)
{
	game->map = game_map;
	game->collected = 0;
	game->moves = 0;
	game->exit_x = -1;
	game->exit_y = -1;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize mlx\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game_map->width * TILE_SIZE,
			game_map->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		perror("Error\nFailed to create window\n");
		return (0);
	}
	if (!load_images(game))
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(1);
	}
	return (1);
}

int	load_images(t_game *game)
{
	game->empty.img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/utils/sprites/empty.xpm",
			&game->empty.width, &game->empty.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/utils/sprites/exit.xpm",
			&game->exit.width, &game->exit.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/utils/sprites/player.xpm",
			&game->player.width, &game->player.height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/utils/sprites/wall.xpm",
			&game->wall.width, &game->wall.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/utils/sprites/coin.xpm",
			&game->collectible.width, &game->collectible.height);
	if (!game->empty.img || !game->exit.img || !game->player.img
		|| !game->wall.img || !game->collectible.img)
	{
		free_images(game);
		perror("Error\nFailed to load one or more images");
		return (0);
	}
	return (1);
}

void	put_tile(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->empty.img, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			put_tile(game, game->map->grid[y][x], x, y);
			if (y == game->map->player_position.y
				&& x == game->map->player_position.x)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->player.img, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
