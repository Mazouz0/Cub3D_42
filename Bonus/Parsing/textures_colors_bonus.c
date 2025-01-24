/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:39:49 by alamini           #+#    #+#             */
/*   Updated: 2025/01/21 18:22:59 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

void	set_texture(char *identifier, char *path, t_gdata *game)
{
	if (!ex_strcmp(identifier, "NO"))
		game->north = path;
	else if (!ex_strcmp(identifier, "SO"))
		game->south = path;
	else if (!ex_strcmp(identifier, "WE"))
		game->west = path;
	else if (!ex_strcmp(identifier, "EA"))
		game->east = path;
}

void	set_color(char *identifier, int arr[3], t_gdata *game)
{
	if (!ex_strcmp(identifier, "F"))
		game->floor = get_rgba(arr[0], arr[1], arr[2], 0xFF);
	else if (!ex_strcmp(identifier, "C"))
		game->ceiling = get_rgba(arr[0], arr[1], arr[2], 0xFF);
}

void	init_elements(t_elements *elements)
{
	elements->map = 0;
	elements->no = 0;
	elements->so = 0;
	elements->we = 0;
	elements->ea = 0;
	elements->f = 0;
	elements->c = 0;
}

int	check_elements_count(t_elements elements)
{
	if (elements.no > 1
		|| elements.so > 1
		|| elements.we > 1
		|| elements.ea > 1
		|| elements.f > 1
		|| elements.c > 1)
		return (1);
	if (elements.no == 1
		&& elements.so == 1
		&& elements.we == 1
		&& elements.ea == 1
		&& elements.f == 1
		&& elements.c == 1)
		return (2);
	return (0);
}

int	textures_colors_parse(int fd, t_gdata *game)
{
	t_elements	elem_parse;
	char		*line;

	init_elements(&elem_parse);
	line = get_line(get_next_line(fd));
	while (line)
	{
		game->map.start++;
		if (validate_texture_color(line, &elem_parse, game))
			ft_clean(NULL, "Invalid map content!!");
		if (check_elements_count(elem_parse) == 1)
			ft_clean(NULL, "Invalid map content!!");
		else if (check_elements_count(elem_parse) == 2)
			break ;
		line = get_line(get_next_line(fd));
	}
	return (fd);
}
