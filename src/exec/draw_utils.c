/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:53:18 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/13 07:22:44 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (x < 0 || x >= WIND_WID)
		return ;
	if (y < 0 || y >= WIND_HEI)
		return ;
	mlx_put_pixel(img , x, y, color);
}

void	draw_circle(mlx_image_t *mlx, int x, int y, long color)
{
	int i;
	int j;
	int r;
	int r2;

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

void	draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2, uint32_t color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		put_pixel(img, x1, y1, color); 
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
		    err -= dy;
		    x1 += sx;
		}
		if (e2 < dx)
		{
		    err += dx;
		    y1 += sy;
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
