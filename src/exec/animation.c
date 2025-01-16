/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:59:35 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/16 18:39:45 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	draw_animation(t_game *game)
{
	// static int	fram;
	mlx_texture_t	*txtr;
	static mlx_image_t		*img;


	// if (fram >= 30)
	// 	fram = 0;
	// txtr = mlx_load_png(game->drag_anim[fram]);
	// img = mlx_texture_to_image(game->mlx, txtr);
	// // mlx_image_to_window(game->mlx, img, WIND_WID / 2, 0);
	// fram ++;

	mlx_delete_image(game->mlx, img);
	txtr = mlx_load_png(game->drag_anim[12]);
	img = mlx_texture_to_image(game->mlx, txtr);
	mlx_resize_image(img, 300, 300);
	mlx_image_to_window(game->mlx, img, WIND_WID / 2, 0);
	
	
	// mlx_delete_texture(txtr);
}