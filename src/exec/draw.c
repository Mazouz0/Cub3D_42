/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:34:33 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/09 07:28:21 by mohmazou         ###   ########.fr       */
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
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1; // Step in x direction
    int sy = (y1 < y2) ? 1 : -1; // Step in y direction
    int err = dx - dy;

    while (1)
	{
        put_pixel(img, x1, y1, color); // Draw the current pixel

        // Check if the end point is reached
        if (x1 == x2 && y1 == y2)
			break;
			
        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void	draw_rect(t_game *game, int x, int y, int w, int h, int color)	// draw the rectangle
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			put_pixel(game->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

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

void	draw_map(t_game *game)
{
	draw_2d(game);
	drwa_plyr(game);
}