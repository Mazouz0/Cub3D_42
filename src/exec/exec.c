/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:44:55 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/07 21:58:38 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"


void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIND_WID, WIND_HEI);
	player_hook(game, 0, 0);
	// ray_cast(game);
	// draw_3d(game);
	draw_map(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	// mlx_key_hook(game->mlx, key_hook, game);

}
