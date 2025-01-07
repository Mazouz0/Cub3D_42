/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:59:40 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/07 23:21:06 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	rotate_player(t_game *game, int i)
{
	if (i == 1)
	{
		game->ply->angle_dir += ROT_SPEED;
		if (game->ply->angle_dir > 2 * M_PI)
			game->ply->angle_dir -= 2 * M_PI;
	}
	else if (i == -1)
	{
		game->ply->angle_dir -= ROT_SPEED;
		if (game->ply->angle_dir < 0)
			game->ply->angle_dir += 2 * M_PI;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = (int)round(game->ply->p_x + move_x); // get the new x position
	new_y = (int)round(game->ply->p_y + move_y); // get the new y position
	map_x = (new_x / TIL_SIZE); // get the x position in the map
	map_y = (new_y / TIL_SIZE); // get the y position in the map
	if (game->dt->map2d[map_y][map_x] != '1') // check the wall hit and the diagonal wall hit
	{
		game->ply->p_x = new_x; // move the player
		game->ply->p_y = new_y; // move the player
	}
}

void	player_hook(t_game *game, double move_x, double move_y)
{
	int	forward;

	forward = game->ply->l_r;
	rotate_player(game, game->ply->rot);
	if (forward == 1)
	{
		move_x = -sin(game->ply->angle_dir) * MOV_SPEED;
		move_y = cos(game->ply->angle_dir) * MOV_SPEED;
	}
	if (forward == -1)
	{
		move_x = sin(game->ply->angle_dir) * MOV_SPEED;
		move_y = -cos(game->ply->angle_dir) * MOV_SPEED;
	}
	forward = game->ply->u_d;
	if (forward != 0)
	{
		move_x = forward * cos(game->ply->angle_dir) * MOV_SPEED;
		move_y = forward * sin(game->ply->angle_dir) * MOV_SPEED;
	}
	move_player(game, move_x, move_y);
}
