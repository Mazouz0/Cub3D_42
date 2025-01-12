/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:34:33 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/12 05:00:26 by alamini          ###   ########.fr       */
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
				draw_rect(game, j * TIL_SIZE, i * TIL_SIZE, TIL_SIZE, TIL_SIZE, 0x00FFBBBB);
			else
				draw_rect(game, j * TIL_SIZE, i * TIL_SIZE, TIL_SIZE, TIL_SIZE, 0xFFFFFFBB);
			j ++;
		}
		i ++;
	}
}

void	drwa_plyr(t_game *game)
{
	int	p_x;
	int	p_y;
	double	angle;
	int		i;

	p_x = game->ply->p_x;
	p_y = game->ply->p_y;
	angle = game->ply->angle_dir;
	i = 0;
	draw_circle(game->img, p_x, p_y, 0xFF0000BB);
	draw_line(game->img, p_x, p_y,
			  p_x + cos(angle) * TIL_SIZE,
			  p_y + sin(angle) * TIL_SIZE,
			  0xFF0000BB);
	angle -= game->ply->fov_rd / 2;
	while (i < WIND_WID)
	{
		draw_line(game->img, p_x, p_y,
				  p_x + cos(angle) * game->rays_dist[i],
				  p_y + sin(angle) * game->rays_dist[i],
				  0xFF0000BB);
		angle += game->ply->fov_rd / WIND_WID;
		i++;
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
	// while (i < WIND_HEI)
	// {
	// 	if (i < WIND_HEI / 2 - wall_h / 2)
	// 		put_pixel(game->img, index, i, game->dt->c_clr);
	// 	else if (i < WIND_HEI / 2 + wall_h / 2)
	// 		ray_3d(game, index, i, ray);
	// 	else
	// 		put_pixel(game->img, index, i, game->dt->f_clr);
	// 	i++;
	// }
}

void	draw_background(t_game *game)
{
	draw_rect(game, 0, 0, WIND_WID, WIND_HEI / 2, game->dt->c_clr);
	draw_rect(game, 0, WIND_HEI / 2, WIND_WID, WIND_HEI / 2, game->dt->f_clr);
}

void	draw_map(t_game *game)
{
	// draw_background(game);
	ray_cast(game);
	draw_2d(game);
	drwa_plyr(game);
}