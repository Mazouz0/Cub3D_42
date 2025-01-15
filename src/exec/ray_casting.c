/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:29:20 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/15 08:21:43 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	inter_check(double angle, double *inter, double *step, int flag)
{
	if (flag)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TIL_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI_2 && angle < 3 * M_PI_2))
		{
			*inter += TIL_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(double x, double y, t_game *game)
{
	int		map_x;
	int		map_y;
	char	**map;

	if (x < 0 || y < 0)
		return (0);
	map = game->dt->map2d;
	map_x = floor(x / TIL_SIZE);
	map_y = floor(y / TIL_SIZE);
	if (map_x < 0 || map_y < 0)
		return (0);
	if (map_y >= game->dt->map_h || map_x >= game->dt->map_w)
		return (0);
	if (map[map_y] && map_x <= (int)ex_strlen(map[map_y]))
		if (map[map_y][map_x] == '1')
			return (0);
	return (1);
}

double	horz_inter(t_ray *ray_dt, t_game *game)
{
	double	xstep;
	double	ystep;
	double	xinter;
	double	yinter;
	int		pixel;

	ray_dt->r_angle = nor_angle(ray_dt->r_angle);
	ystep = TIL_SIZE;
	xstep = TIL_SIZE / tan(ray_dt->r_angle);
	yinter = floor(game->ply->p_y / TIL_SIZE) * TIL_SIZE;
	pixel = inter_check(ray_dt->r_angle, &yinter, &ystep, 1);
	xinter = game->ply->p_x + (yinter - game->ply->p_y) / tan(ray_dt->r_angle);
	if ((unit_circle(ray_dt->r_angle, 'y') && xstep > 0)
		|| (!unit_circle(ray_dt->r_angle, 'y') && xstep < 0))
		xstep *= -1;
	while (wall_hit(xinter, yinter - pixel, game))
	{
		xinter += xstep;
		yinter += ystep;
	}
	ray_dt->horz_x = xinter;
	ray_dt->horz_y = yinter;
	return (sqrt(pow(game->ply->p_x - xinter, 2)
			+ pow(game->ply->p_y - yinter, 2)));
}

double	vert_inter(t_ray *ray_dt, t_game *game)
{
	double	xstep;
	double	ystep;
	double	xinter;
	double	yinter;
	int		pixel;

	ray_dt->r_angle = nor_angle(ray_dt->r_angle);
	xstep = TIL_SIZE;
	ystep = TIL_SIZE * tan(ray_dt->r_angle);
	xinter = floor(game->ply->p_x / TIL_SIZE) * TIL_SIZE;
	pixel = inter_check(ray_dt->r_angle, &xinter, &xstep, 0);
	yinter = game->ply->p_y + (xinter - game->ply->p_x) * tan(ray_dt->r_angle);
	if ((unit_circle(ray_dt->r_angle, 'x') && ystep < 0)
		|| (!unit_circle(ray_dt->r_angle, 'x') && ystep > 0))
		ystep *= -1;
	while (wall_hit(xinter - pixel, yinter, game))
	{
		xinter += xstep;
		yinter += ystep;
	}
	ray_dt->vert_x = xinter;
	ray_dt->vert_y = yinter;
	return (sqrt(pow(game->ply->p_x - xinter, 2)
			+ pow(game->ply->p_y - yinter, 2)));
}

void	ray_cast(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	game->ray->r_angle = game->ply->angle_dir - (game->ply->fov_rd / 2);
	while (ray < WIND_WID)
	{
		game->ray->flag = 0;
		h_inter = horz_inter(game->ray, game);
		v_inter = vert_inter(game->ray, game);
		if (v_inter <= h_inter)
			game->ray->distance = v_inter;
		else
		{
			game->ray->distance = h_inter;
			game->ray->flag = 1;
		}
		draw_3d(game, game->ray, ray);
		ray ++;
		game->ray->r_angle += game->ply->fov_rd / WIND_WID;
	}
}
