/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 07:15:10 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/17 21:57:45 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

int is_door(double x, double y, t_game *game)
{
    int map_x;
    int map_y;
    
    // Try both floor and ceil for edge cases
    map_x = floor(x / TIL_SIZE);
    map_y = floor(y / TIL_SIZE);
    
    // Check first position
    if (map_x >= 0 && map_y >= 0 && 
        map_y < game->dt->map_h && map_x < game->dt->map_w &&
        game->dt->map2d[map_y] && 
        map_x <= (int)ex_strlen(game->dt->map2d[map_y]) &&
        game->dt->map2d[map_y][map_x] == 'D')
        return (1);
        
    // Try ceil for edge cases
    map_x = ceil(x / TIL_SIZE) - 1;
    map_y = ceil(y / TIL_SIZE) - 1;
    
    // Check second position
    if (map_x >= 0 && map_y >= 0 && 
        map_y < game->dt->map_h && map_x < game->dt->map_w &&
        game->dt->map2d[map_y] && 
        map_x <= (int)ex_strlen(game->dt->map2d[map_y]) &&
        game->dt->map2d[map_y][map_x] == 'D')
        return (1);
        
    return (0);
}

mlx_texture_t	*get_texture_exec(t_game *game, int flag)
{
	game->ray->r_angle = nor_angle(game->ray->r_angle);
	
	if (flag == 0)
	{
		if (is_door(game->ray->vert_x, game->ray->vert_y, game))
			return (game->dt->txtr->door);
		else if (game->ray->r_angle > M_PI / 2 && game->ray->r_angle
			< 3 * (M_PI / 2))
			return (game->dt->txtr->ea);
		else
			return (game->dt->txtr->we);
	}
	else
	{
		if (is_door(game->ray->horz_x, game->ray->horz_y, game))
			return (game->dt->txtr->door);
		else if (game->ray->r_angle > 0 && game->ray->r_angle < M_PI)
			return (game->dt->txtr->so);
		else
			return (game->dt->txtr->no);
	}
}

double	get_x_o(mlx_texture_t	*texture, t_game *game)
{
	double	x_o;

	if (game->ray->flag == 1)
		x_o = (int)fmodf((game->ray->horz_x
					* (texture->width / TIL_SIZE)), texture->width);
	else
		x_o = (int)fmodf((game->ray->vert_y
					* (texture->width / TIL_SIZE)), texture->width);
	return (x_o);
}

void	draw_wall(t_game *game, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_texture_exec(game, game->ray->flag);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, game);
	y_o = (t_pix - (WIND_HEI / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		put_pixel(game->img, game->ray->index, t_pix,
			reverse_bytes(arr[(int)y_o * texture->width + (int)x_o]));
		y_o += factor;
		t_pix++;
	}
}

void	ray_3d(t_game *game, int index, t_ray *ray, double wall_h)
{
	double	b_pix;
	double	t_pix;

	ray->distance *= cos(nor_angle(ray->r_angle - game->ply->angle_dir));
	b_pix = (WIND_HEI / 2) + (wall_h / 2);
	t_pix = (WIND_HEI / 2) - (wall_h / 2);
	if (b_pix > WIND_HEI)
		b_pix = WIND_HEI;
	if (t_pix < 0)
		t_pix = 0;
	ray->index = index;
	draw_wall(game, t_pix, b_pix, wall_h);
}
