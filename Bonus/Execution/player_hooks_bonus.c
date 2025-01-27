/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:59:40 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:06 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

int	norm_pos_x(char **map, int map_x, int map_y, int new_x)
{
	if (!not_1d(map, map_x + 1, map_y)
		&& (new_x % TIL_SIZE) > (TIL_SIZE - WALL_BUFFER))
		return ((map_x * TIL_SIZE) + (TIL_SIZE - WALL_BUFFER));
	if (!not_1d(map, map_x - 1, map_y)
		&& (new_x % TIL_SIZE) < WALL_BUFFER)
		return ((map_x * TIL_SIZE) + WALL_BUFFER);
	return (new_x);
}

int	norm_pos_y(char **map, int map_x, int map_y, int new_y)
{
	if (!map || !map[map_y] || !map[map_y + 1] || !map[map_y - 1])
		return (new_y);
	if (!not_1d(map, map_x, map_y + 1)
		&& (new_y % TIL_SIZE) > (TIL_SIZE - WALL_BUFFER))
		return ((map_y * TIL_SIZE) + (TIL_SIZE - WALL_BUFFER));
	if (!not_1d(map, map_x, map_y - 1)
		&& (new_y % TIL_SIZE) < WALL_BUFFER)
		return ((map_y * TIL_SIZE) + WALL_BUFFER);
	return (new_y);
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;
	char	**map;

	new_x = (int)round(game->ply->p_x + move_x);
	new_y = (int)round(game->ply->p_y + move_y);
	map_x = (new_x / TIL_SIZE);
	map_y = (new_y / TIL_SIZE);
	map = game->dt->map2d;
	new_x = norm_pos_x(map, map_x, map_y, new_x);
	new_y = norm_pos_y(map, map_x, map_y, new_y);
	if (not_1d(map, map_x, map_y) && not_1d(map, game->ply->p_x
			/ TIL_SIZE, map_y) && not_1d(map, map_x, game->ply->p_y / TIL_SIZE))
	{
		game->ply->p_x = new_x;
		game->ply->p_y = new_y;
	}
	else if (not_1d(map, map_x, game->ply->p_y / TIL_SIZE)
		&& not_1d(map, map_x, map_y))
	{
		game->ply->p_x = new_x;
		game->ply->p_y = new_y;
	}
}

void	player_hook(t_game *game, double move_x, double move_y)
{
	int	forward;

	forward = game->ply->l_r;
	if (forward == 1)
	{
		move_x = -sin(game->ply->angle_dir) * MOV_SPEED;
		move_y = cos(game->ply->angle_dir) * MOV_SPEED;
	}
	else if (forward == -1)
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
