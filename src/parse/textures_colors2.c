/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_colors2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:52:47 by alamini           #+#    #+#             */
/*   Updated: 2025/01/13 01:51:19 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	is_a_texture(char *str, t_elements *elements)
{
	if (!ex_strcmp(str, "NO"))
		return (elements->no += 1, 0);
	if (!ex_strcmp(str, "SO"))
		return (elements->so += 1, 0);
	if (!ex_strcmp(str, "WE"))
		return (elements->we += 1, 0);
	if (!ex_strcmp(str, "EA"))
		return (elements->ea += 1, 0);
	return (1);
}

int	get_texture(char *identifier, char *line, t_gdata *game)
{
	int		i;
	char	*tmp;
	char	*path;
	int		fd;

	tmp = line;
	i = 0;
	while (tmp && *tmp == ' ')
		tmp ++;
	tmp += 2;
	while (*tmp == ' ')
		tmp ++;
	path = malloc(ex_strlen(tmp));
	while (tmp[i] != '\n')
	{
		path[i] = tmp[i];
		i ++;
	}
	path[i] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_clean(NULL, "Invalid texture path"), 1);
	set_texture(identifier, path, game);
	return (close(fd), 0);
}

int	is_color(char **dbl_ptr, t_elements *elements)
{
	if (count_elements(dbl_ptr) > 3)
		return (1);
	if (count_elements(dbl_ptr) == 3
		&& ex_strcmp(dbl_ptr[count_elements(dbl_ptr) - 1], "\n"))
	{
		return (1);
	}
	if (!ex_strcmp(dbl_ptr[0], "F"))
		return (elements->f += 1, 0);
	if (!ex_strcmp(dbl_ptr[0], "C"))
		return (elements->c += 1, 0);
	return (1);
}

int	get_color(char *identifier, char *str, t_gdata *game)
{
	char	**dbl_ptr;
	int		i;
	char	*color;

	i = 0;
	color = ft_malloc(ex_strlen(str), 0);
	if (!color)
		return (ft_clean(NULL, "Allocation Error!"), 1);
	while (str[i] && str[i] != '\n')
	{
		color[i] = str[i];
		i++;
	}
	color[i] = '\0';
	dbl_ptr = ft_split(color, ',');
	if (count_elements(dbl_ptr) != 3 || is_number(dbl_ptr[0])
		|| is_number(dbl_ptr[1]) || is_number(dbl_ptr[2]))
		return (1);
	if (fill_rgb(game, dbl_ptr, identifier))
		return (ft_clean(NULL, "Invalid Flor-Ceiling RGB"), 1);
	return (0);
}

int	validate_texture_color(char *line, t_elements *elements, t_gdata *game)
{
	int		ce;
	char	**dbl_ptr;

	dbl_ptr = ft_split(line, ' ');
	ce = count_elements(dbl_ptr);
	if (!ex_strcmp(dbl_ptr[0], "\n"))
		return (0);
	if (ce < 2)
		return (1);
	if (!is_a_texture(dbl_ptr[0], elements))
		return (get_texture(dbl_ptr[0], line, game));
	if (!is_color(dbl_ptr, elements))
		return (get_color(dbl_ptr[0], dbl_ptr[1], game));
	return (1);
}