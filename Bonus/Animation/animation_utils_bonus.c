/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:01 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 19:49:40 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

void	put_to_image_gun(t_game *game, t_anim_dt *data)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;
	uint32_t	max_pixels;
	uint32_t	current_pixel;

	max_pixels = data->width * data->height;
	y = 0;
	while (y < data->height && y < game->img->height)
	{
		x = 0;
		while (x < data->width && x < game->img->width)
		{
			current_pixel = y * data->width + x;
			if (current_pixel < max_pixels)
			{
				color = data->pixels[y * data->width + x];
				if (color != 0)
					put_pixel(game->img, x + WIND_WID / 2 - data->width / 2,
						y + WIND_HEI - data->height, reverse_bytes(color));
			}
			x++;
		}
		y++;
	}
}

char	*an_strdup(char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ex_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*an_strjoin(char *str1, char *str2)
{
	char	*res;
	int		length;

	if ((!str1 && !str2))
		return (NULL);
	else if (!str1)
		return (an_strdup(str2));
	else if (!str2)
		return (an_strdup(str1));
	length = ex_strlen(str1) + ex_strlen(str2);
	res = (char *)malloc(sizeof(char) * length + 1);
	if (!res)
		return (NULL);
	res = gnl_strcpy(str1, str2, res);
	return (res);
}
