/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:01 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/17 18:52:31 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

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
