/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:59:35 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/18 12:56:01 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	put_to_image_spiret(t_game *game, t_anim_dt *data)
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
					put_pixel(game->img, x + WIND_WID - data->width,
						y, reverse_bytes(color));
			}
			x++;
		}
		y++;
	}
}

t_anim_dt	*init_anim(char *animation, mlx_texture_t **tex_ptr)
{
	t_anim_dt		*anim;
	mlx_texture_t	*texture;

	texture = mlx_load_png(animation);
	if (!texture)
		return (NULL);
	anim = ft_malloc(sizeof(t_anim_dt *), 0);
	if (!anim)
		return (mlx_delete_texture(texture), NULL);
	anim->height = texture->height;
	anim->width = texture->width;
	anim->pixels = (uint32_t *)texture->pixels;
	*tex_ptr = texture;
	return (anim);
}

char	*get_gun(int i)
{
	char	*gun;
	char	*tmp;

	tmp = ex_strjoin("t_animation/gun/", ft_itoa(i + 1));
	gun = ex_strjoin(tmp, ".png");
	return (gun);
}

t_anim_dt	*init_gun(int gun, mlx_texture_t **tex_ptr)
{
	t_anim_dt		*anim;
	mlx_texture_t	*texture;

	texture = mlx_load_png(get_gun(gun));
	if (!texture)
		return (NULL);
	anim = ft_malloc(sizeof(t_anim_dt *), 0);
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
	static int		skult;
	static int		gun;
	mlx_texture_t	*skult_txr;
	mlx_texture_t	*gun_txt;

	skult_txr = NULL;
	gun_txt = NULL;
	if (skult == 76)
		skult = 0;
	if (gun == 15)
	{
		gun = 0;
		game->gun = 0;
	}
	put_to_image_spiret(game, init_anim(game->anime[skult ++], &skult_txr));
	if (game->gun)
		put_to_image_gun(game, init_gun(gun ++, &gun_txt));
	if (skult_txr)
		mlx_delete_texture(skult_txr);
	if (gun_txt)
		mlx_delete_texture(gun_txt);
}
