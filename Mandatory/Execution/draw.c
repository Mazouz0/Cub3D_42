/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:34:33 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 18:00:09 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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
}
