/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:16:39 by alamini           #+#    #+#             */
/*   Updated: 2025/01/18 11:29:38 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (i < 4)
		return (ft_error("Invalid map name"));
	i--;
	if (file_name[i] != 'b' || file_name[i - 1] != 'u'
		|| file_name[i - 2] != 'c' || file_name[i - 3] != '.')
	{
		return (ft_error("Invalid map name"));
	}
	return (0);
}

t_gdata	*init_data(char *file)
{
	t_gdata	*game;

	game = ft_malloc(sizeof(t_gdata), 0);
	if (!game)
	{
		ft_clean(NULL, "Allocation Error!!");
		exit(1);
	}
	game->map.max_column = 0;
	game->map.max_row = 0;
	game->map.the_map = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->floor = -1;
	game->ceiling = -1;
	game->file = file;
	game->map.start = 0;
	return (game);
}

int	map_direction(char c)
{
	if (c == 'E')
		return (0);
	if (c == 'S')
		return (1);
	if (c == 'W')
		return (2);
	if (c == 'N')
		return (3);
	return (0);
}

void	get_player_info(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->the_map[i])
	{
		j = 0;
		while (map->the_map[i][j])
		{
			if (in_set("NSEW", map->the_map[i][j]))
			{
				map->player.x = j;
				map->player.y = i;
				map->direction = map_direction(map->the_map[i][j]);
				map->the_map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

t_gdata	*parsing(int argc, char **argv)
{
	t_gdata		*game;
	int			fd;

	game = NULL;
	if (argc != 2)
		return (ft_clean(NULL, "Invalid arguments!!"), NULL);
	if (check_file_name(argv[1]))
		return (NULL);
	game = init_data(argv[1]);
	fd = open(game->file, O_RDONLY);
	if (fd == -1)
		return (ft_clean(NULL, "Invalid map file!!"), NULL);
	fd = textures_colors_parse(fd, game);
	if (fd == -1)
		return (ft_clean(NULL, "Invalid map content!!"), NULL);
	if (map_parse(fd, game))
		return (ft_clean(NULL, "Invalid map content!!"), NULL);
	if (get_map(fd, game))
		return (NULL);
	if (map_borders(game->map) || validate_map(game->map))
		return (NULL);
	get_player_info(&game->map);
	return (game);
}
