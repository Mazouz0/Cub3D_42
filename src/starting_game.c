/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:00:40 by alamini           #+#    #+#             */
/*   Updated: 2024/12/23 18:20:05 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

void    init_game(t_game *game)
{
    void	*mlx;
	void	*mlx_win;
    t_data  img;

    game->width = 1920 / game->map.max_column;
    game->height = 1080 / game->map.max_row;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "CUB3D");
    img.img = mlx_new_image(mlx, 1920, 1080);
    printf("Line length |%d|\n", img.line_length);
    printf("bits per pixel |%d|\n", img.bits_per_pixel);
    printf("endian |%d|\n", img.endian);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    printf("Line length |%d|\n", img.line_length);
    printf("bits per pixel |%d|\n", img.bits_per_pixel);
    printf("endian |%d|\n", img.endian);
    
	mlx_loop(mlx);
}