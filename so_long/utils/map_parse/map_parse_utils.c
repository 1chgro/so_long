/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:54:42 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/19 02:28:39 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		perror("Error\nusage: ./so_long <map_path> \t");
		return (0);
	}
	if (!valid_file_format(av[1]))
	{
		perror("Error\ninvalid file type \t");
		return (0);
	}
	return (1);
}

t_map	*init_map(void)
{
	t_map	*game_map;

	game_map = malloc(sizeof(t_map));
	if (!game_map)
		return (NULL);
	game_map->grid = NULL;
	game_map->players = 0;
	game_map->exits = 0;
	game_map->collectibles = 0;
	game_map->width = 0;
	game_map->height = 0;
	return (game_map);
}

int	valid_file_format(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strcmp(file_name + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	map_line_width(char *line)
{
	int	width;

	width = 0;
	if (!line)
		return (0);
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'E'
		|| c == 'C' || c == 'P' || c == '\n');
}
