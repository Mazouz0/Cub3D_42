/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:59:35 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/17 00:15:04 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	put_to_image(t_game *game, t_anim_dt *data)
{
	
    uint32_t    x;
    uint32_t    y;
    uint32_t    color;
    uint32_t    max_pixels;
    uint32_t    current_pixel;

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
					put_pixel(game->img, x + WIND_WID / 2 - data->width / 2
					, y + WIND_HEI - data->height, reverse_bytes(color) );
			}
			x++;
		}
		y++;
	}
}

t_anim_dt	*init_anim(char *animation,  mlx_texture_t **tex_ptr)
{
	t_anim_dt	*anim;
	mlx_texture_t	*texture;

	anim = ft_malloc(sizeof(t_anim_dt *), 0);
	if (!anim)
		return (NULL);
	texture = mlx_load_png(animation);
	if (!texture)
		return (NULL);
	anim = ft_malloc(sizeof(t_anim_dt), 0);
	if (!anim)
		return (mlx_delete_texture(texture), NULL);
	anim->height = texture->height;
	anim->width = texture->width;
	anim->pixels = (uint32_t *)texture->pixels;
	*tex_ptr = texture;
	return (anim);
}
void	draw_animation(t_game *game)
{
	static int	fram;
	mlx_texture_t	*texture;

	texture = NULL;
	if (fram == 250)
		fram = 0;
	put_to_image(game, init_anim(game->anime[fram ++], &texture));
	mlx_delete_texture(texture);
	

}