/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:35:22 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/30 23:53:16 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define TILE_SIZE 32

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

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

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	player;
	t_img	wall;
	t_img	exit;
	t_img	empty;
	t_img	collectible;
	int		collected;
	int		moves;
	int		exit_x;
	int		exit_y;
}	t_game;

t_map	*init_map(void);
t_map	*parse_map(int ac, char **av);
int		validate_args(int ac, char **av);
int		valid_file_format(char *file_name);
int		validate_map_components(t_map *game_map);
int		is_valid_map_char(char c);
int		map_line_width(char *line);
int		get_map_width_height(t_map *game_map, char *map_file);
int		check_walls(t_map *map);
int		check_map_line(t_map *game_map, char *line, int y);
int		map_grid_fill(t_map *game_map, char *map_file);
void	free_map(t_map *map);

char	**create_temp_grid(t_map *map);
void	copy_grid(char **temp_grid, t_map *map);
void	flood_fill(char **temp_grid, int x, int y, t_map *map);
int		check_reach(char **temp_grid, t_map *map);
int		check_path(t_map *map);
void	free_temp_grid(char **temp_grid, t_map *map);

int		init_game(t_game *game, t_map *game_map);
void	render_map(t_game *game);
int		load_images(t_game *game);
void	free_images(t_game *game);
int		handle_keys(int keysym, t_game *game);
int		move_player(t_game *game, int dx, int dy);
int		close_game(t_game *game);
#endif  