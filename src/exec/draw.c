/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:34:33 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/15 13:34:29 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	draw_2d(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->dt->map2d;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_rect(game, j * TIL_SIZE, i * TIL_SIZE, 0xBBBBBB99);
			else
				draw_rect(game, j * TIL_SIZE, i * TIL_SIZE, 0xFFFFFFBB);
			j ++;
		}
		i ++;
	}
}

void	drwa_plyr(t_game *game)
{
	int		p_x;
	int		p_y;
	double	angle;
	int		i;

	p_x = game->ply->p_x;
	p_y = game->ply->p_y;
	angle = game->ply->angle_dir - game->ply->fov_rd / 2;
	i = 0;
	draw_circle(game->img, p_x, p_y, 0xFF0000BB);
	while (i < 100)
	{
		draw_t_line(game->img, (t_cordinates){p_x, p_y},
			(t_cordinates){p_x + cos(angle) * TIL_SIZE,
			p_y + sin(angle) * TIL_SIZE}, 0xFF0000BB);
		angle += game->ply->fov_rd / 100;
		i ++;
	}
}

void	draw_3d(t_game *game, t_ray *ray, int index)
{
	double	dist;
	double	wall_h;
	double	dist_p;
	int		i;

	i = 0;
	dist = ray->distance * cos(ray->r_angle - game->ply->angle_dir);
	dist_p = (WIND_WID / 2) / tan(game->ply->fov_rd / 2);
	wall_h = (TIL_SIZE / dist) * dist_p;
	while (i < WIND_HEI / 2 - wall_h / 2)
		put_pixel(game->img, index, i ++, game->dt->c_clr);
	ray_3d(game, index, ray, wall_h);
	i = WIND_HEI / 2 + wall_h / 2;
	while (i < WIND_HEI)
		put_pixel(game->img, index, i ++, game->dt->f_clr);
}

void	draw_map(t_game *game)
{
	ray_cast(game);
	draw_2d(game);
	drwa_plyr(game);
}
