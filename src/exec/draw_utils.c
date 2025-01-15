/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:53:18 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/15 08:07:14 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (x < 0 || x >= WIND_WID)
		return ;
	if (y < 0 || y >= WIND_HEI)
		return ;
	mlx_put_pixel(img, x, y, color);
}

void	draw_circle(mlx_image_t *mlx, int x, int y, long color)
{
	int	i;
	int	j;
	int	r;
	int	r2;

	r = 3;
	r2 = r * r;
	i = -r;
	while (i <= r)
	{
		j = -r;
		while (j <= r)
		{
			if ((i * i) + (j * j) <= r2)
				put_pixel(mlx, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	get_s(int c1, int c2)
{
	if (c1 < c2)
		return (1);
	return (-1);
}

void	draw_t_line(mlx_image_t *img, t_cordinates c1
	, t_cordinates c2, uint32_t color)
{
	t_utils	u;

	u.dx = abs(c2.x - c1.x);
	u.dy = abs(c2.y - c1.y);
	u.sx = get_s(c1.x, c2.x);
	u.sy = get_s(c1.y, c2.y);
	u.err = u.dx - u.dy;
	while (1)
	{
		put_pixel(img, c1.x, c1.y, color);
		if (c1.x == c2.x && c1.y == c2.y)
			break ;
		u.e2 = 2 * u.err;
		if (u.e2 > -u.dy)
		{
			u.err -= u.dy;
			c1.x += u.sx;
		}
		if (u.e2 < u.dx)
		{
			u.err += u.dx;
			c1.y += u.sy;
		}
	}
}

void	draw_rect(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TIL_SIZE)
	{
		j = 0;
		while (j < TIL_SIZE)
		{
			put_pixel(game->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
