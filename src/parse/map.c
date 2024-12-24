/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:10:24 by alamini           #+#    #+#             */
/*   Updated: 2024/12/24 18:24:40 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/cube.h"

int is_valid(char *line, int *count)
{
	int i;
	char possible_chars[] = "\n01 NSWE";

	i = 0;
	while (line[i] && line[i] == ' ')
		i ++;
	if (line[i] != '1')
		return (1);
	while (line[i])
	{
		if (in_set(&possible_chars[4], line[i]))
			(*count)++;
		if (!in_set(possible_chars, line[i]))
			return (1);
		i++;
	}
	return (0);
}

int parse_line(char *line, int *count)
{
	if (!ex_strcmp(line, "\n"))
		return (1);
	if (is_valid(line, count))
		return (1);
	return (0);
}
int row_length(char *line)
{
	int i;
	
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	while ((line[i] == 32 && i >= 0) || line[i] == '\n' || line[i] == '\0')
		i--;
	i++;
	return (i);
}

void fill_map_info(char *line, t_gdata *game)
{
	int length;

	length = row_length(line);
	if (length > game->map.max_column)
		game->map.max_column = length;
	game->map.max_row++;
}


int map_parse(int fd, t_gdata *game)
{
	char *line;
	int count;

	count = 0;
	line = get_next_line(fd);
	while (ex_strcmp(line, "\n") == 0)
	{
		game->map.start++;
		line = get_next_line(fd);
	}
	while (line)
	{
		if (parse_line(line, &count))
			return (1);
		else
			fill_map_info(line, game);
		line = get_next_line(fd);
	}
	if (count != 1)
		return (1);
	return (0);
}