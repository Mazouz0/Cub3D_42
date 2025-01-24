/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:19:11 by alamini           #+#    #+#             */
/*   Updated: 2025/01/23 20:57:09 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

char	*get_row(char *line, t_gdata *game)
{
	char	*row;
	int		i;

	i = 0;
	row = ft_malloc(sizeof(char) * game->map.max_column + 1, 0);
	if (!row)
		ft_clean(NULL, "Allocation Error");
	while (i < row_length(line))
	{
		row[i] = line[i];
		i++;
	}
	while (i < game->map.max_column)
	{
		row[i] = 32;
		i++;
	}
	row[i] = '\0';
	return (row);
}

int	get_map(int fd, t_gdata *game)
{
	int		i;
	char	*line;
	char	**grid;

	i = -1;
	close(fd);
	grid = ft_malloc((sizeof(char *) * game->map.max_row) + 1, 0);
	fd = open(game->file, O_RDONLY);
	if (!grid || fd == -1)
		ft_clean(NULL, "Resources Error");
	while (++i < game->map.start)
		free(get_next_line(fd));
	i = 0;
	line = get_line(get_next_line(fd));
	while (line && i < game->map.max_row)
	{
		grid[i] = get_row(line, game);
		line = get_line(get_next_line(fd));
		i++;
	}
	grid[i] = NULL;
	game->map.the_map = grid;
	close(fd);
	return (0);
}

int	is_sourounded_by_void(t_map map, int y, int x)
{
	char	**grid;

	grid = map.the_map;
	if (!x || !y || x == map.max_column - 1 || y == map.max_row - 1)
		return (0);
	if (in_set(" ", grid[y - 1][x]))
		return (1);
	else if (in_set(" ", grid[y + 1][x]))
		return (1);
	else if (in_set(" ", grid[y][x - 1]))
		return (1);
	else if (in_set(" ", grid[y][x + 1]))
		return (1);
	return (0);
}

int	validate_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.max_row)
	{
		j = 0;
		while (j < map.max_column)
		{
			if (in_set("NSEW0", map.the_map[i][j]))
				if (is_sourounded_by_void(map, i, j))
					ft_clean(NULL, "Invalid Map");
			j++;
		}
		i++;
	}
	return (0);
}

int	map_borders(t_map map)
{
	int		i;
	char	**grid;
	int		max_row;
	int		max_column;

	grid = map.the_map;
	max_row = map.max_row;
	max_column = map.max_column;
	i = 0;
	while (i < map.max_column)
	{
		if (!in_set("1 ", grid[0][i]) || !in_set("1 ", grid[max_row - 1][i]))
			ft_clean(NULL, "you forgot to build the walls ^_^");
		i++;
	}
	i = 0;
	while (i < map.max_row)
	{
		if (!in_set("1 ", grid[i][0]) || !in_set("1 ", grid[i][max_column - 1]))
			ft_clean(NULL, "you forgot to build the walls ^_^");
		i++;
	}
	return (0);
}
