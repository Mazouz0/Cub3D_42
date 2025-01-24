/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:59:35 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/23 23:25:48 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

void	put_to_image_sprite(t_game *game, t_anim_dt *data)
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

t_anim_dt	*init_anim(t_game *game, char *animation, mlx_texture_t **tex_ptr)
{
	t_anim_dt		*anim;
	mlx_texture_t	*texture;

	texture = mlx_load_png(animation);
	if (!texture)
		ft_clean(game, "Texture loading failed");
	anim = ft_malloc(sizeof(t_anim_dt *), 0);
	if (!anim)
		return (mlx_delete_texture(texture), ft_clean(game, "Allocation error"),
			NULL);
	anim->height = texture->height;
	anim->width = texture->width;
	anim->pixels = (uint32_t *)texture->pixels;
	*tex_ptr = texture;
	return (anim);
}

char	*get_gun(t_game *game, int i)
{
	char	*gun;
	char	*tmp;

	tmp = an_strjoin("t_animation/gun/", ft_itoa(i + 1));
	if (!tmp)
		ft_clean(game, "Malloc failed");
	gun = an_strjoin(tmp, ".png");
	free(tmp);
	if (!gun)
		ft_clean(game, "Malloc failed");
	return (gun);
}

t_anim_dt	*init_gun(t_game *game, int gun, mlx_texture_t **tex_ptr)
{
	t_anim_dt		*anim;
	mlx_texture_t	*texture;
	char			*name;

	name = get_gun(game, gun);
	texture = mlx_load_png(name);
	free(name);
	if (!texture)
		ft_clean(game, "Texture loading failed");
	anim = ft_malloc(sizeof(t_anim_dt *), 0);
	if (!anim)
		return (mlx_delete_texture(texture), ft_clean(game, "Allocation error"),
			NULL);
	anim->height = texture->height;
	anim->width = texture->width;
	anim->pixels = (uint32_t *)texture->pixels;
	*tex_ptr = texture;
	return (anim);
}

void	draw_animation(t_game *game)
{
	static int		skull;
	static int		gun;
	mlx_texture_t	*skull_txr;
	mlx_texture_t	*gun_txt;

	skull_txr = NULL;
	gun_txt = NULL;
	if (skull == SKULL_NBR)
		skull = 0;
	if (gun == 15)
	{
		gun = 0;
		game->gun = 0;
	}
	put_to_image_sprite(game, init_anim(game,
			game->anime[skull ++], &skull_txr));
	if (game->gun)
		put_to_image_gun(game, init_gun(game, gun ++, &gun_txt));
	if (skull_txr)
		mlx_delete_texture(skull_txr);
	if (gun_txt)
		mlx_delete_texture(gun_txt);
}
