/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:52:08 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/28 21:21:22 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define TILE_SIZE 32

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_coin_animation
{
	t_img	coins[8];
	int		current_frame;
	int		frame_counter;
	int		num_frames;
}	t_coin_animation;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
	int			exits;
	int			players;
	t_player	player_position;
}	t_map;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	t_map				*map;
	t_img				player;
	t_img				wall;
	t_img				exit;
	t_img				empty;
	t_img				collectible;
	int					collected;
	int					moves;
	int					exit_x;
	int					exit_y;
	t_coin_animation	coin_anim;
	t_enemy				*enemies;
	int					enemy_count;
	t_img				enemy;
}	t_game;

t_map	*init_map(void);
int		valid_file_format(char *file_name);
int		validate_args(int ac, char **av);
int		map_line_width(char *line);
int		is_valid_map_char(char c);
int		check_walls(t_map *map);
int		get_map_width_height(t_map *game_map, char *map_file);
void	free_map(t_map *map);
int		check_map_line(t_map *game_map, char *line, int y);
int		map_grid_fill(t_map *game_map, char *map_file);
int		validate_map_components(t_map *game_map);
t_map	*parse_map(int ac, char **av);

void	flood_fill(char **temp_grid, int x, int y, t_map *map);
char	**create_temp_grid(t_map *map);
void	copy_grid(char **temp_grid, t_map *map);
void	free_temp_grid(char **temp_grid, t_map *map);
int		check_reach(char **temp_grid, t_map *map);
int		check_path(t_map *map);

void	render_map(t_game *game);
int		init_game(t_game *game, t_map *game_map);
int		load_images(t_game *game);
int		handle_keys(int keysym, t_game *game);
int		move_player(t_game *game, int dx, int dy);
void	moves_count(t_game *game);

int		animation_loop(t_game *game);
void	clean_coin_animation(t_game *game);
void	update_coin_animation(t_game *game);
void	init_coin_animation(t_game *game);

void	count_enemies(t_game *game, int *count);
void	init_enemies(t_game *game);
void	move_enemies(t_game *game);
void	cleanup_enemies(t_game *game);
void	game_over(t_game *game);
void	init_enemy_positions(t_game *game);

#endif