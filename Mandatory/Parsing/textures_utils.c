/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 01:53:41 by alamini           #+#    #+#             */
/*   Updated: 2025/01/21 18:00:41 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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
