/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 01:53:41 by alamini           #+#    #+#             */
/*   Updated: 2025/01/21 18:23:15 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

int	fill_rgb(t_gdata *game, char **dbl_ptr, char *identifier)
{
	int		rgb[3];

	rgb[0] = ft_atoi(dbl_ptr[0]);
	rgb[1] = ft_atoi(dbl_ptr[1]);
	rgb[2] = ft_atoi(dbl_ptr[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
	{
		return (1);
	}
	set_color(identifier, rgb, game);
	return (0);
}

char	*get_line(char *tmp)
{
	char	*line;

	if (!tmp)
		return (NULL);
	line = my_strdup(tmp);
	if (!line)
		ft_clean(NULL, "Malloc failed");
	free(tmp);
	return (line);
}

int	is_valid_door(t_map map, int y, int x)
{
	char	**grid;

	grid = map.the_map;
	if (!x || !y || x == map.max_column - 1 || y == map.max_row - 1)
		return (0);
	if (grid[y - 1][x] == '1' && grid[y + 1][x] == '1')
		return (0);
	else if (grid[y][x - 1] == '1' && grid[y][x + 1] == '1')
		return (0);
	return (1);
}

int	check_doors(t_map map)
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
			if (in_set("DO", map.the_map[i][j]))
				if (is_valid_door(map, i, j))
					ft_clean(NULL, "Invalid Door placement");
			j++;
		}
		i++;
	}
	return (0);
}
