/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:34:33 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/17 13:14:20 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	drwa_plyr(t_game *game)
{
	int		p_x;
	int		p_y;
	double	angle;
	int		i;

	p_x = 5 * TIL_SIZE ;
	p_y = 5 * TIL_SIZE ;
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

void	draw_2d(t_game *game, int p_x, int p_y)
{
	int		i;
	int		j;
	int		o_x;
	int		o_y;

	o_x = game->ply->p_x - (5 * TIL_SIZE);
	o_y = game->ply->p_y - (5 * TIL_SIZE);
	i = p_x - 6;
	while (++ i <= p_x + 5)
	{
		j = p_y - 6;
		while (++j <= p_y + 5)
		{
			if (i >= 0 && j >= 0 && i < game->dt->map_w && j < game->dt->map_h)
			{
				if (game->dt->map2d[j][i] == '1')
					draw_rect(game, (i * TIL_SIZE) - o_x,
						(j * TIL_SIZE) - o_y, 0xBBBBBB99);
				else
					draw_rect(game, (i * TIL_SIZE) - o_x,
						(j * TIL_SIZE) - o_y, 0xFFFFFFBB);
			}
		}
	}
	drwa_plyr(game);
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
	draw_2d(game, game->ply->p_x / TIL_SIZE, game->ply->p_y / TIL_SIZE);
	draw_animation(game);
}
