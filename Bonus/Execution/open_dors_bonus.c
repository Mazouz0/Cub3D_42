/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_open_dors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:00:13 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:04 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

void	change_map(char **map, int p_mx, int p_my, t_game *game)
{
	int	ply_x;
	int	ply_y;

	ply_x = game->ply->p_x;
	ply_y = game->ply->p_y;
	if (map[p_my][p_mx - 1] == 'D')
		map[p_my][p_mx - 1] = 'O';
	else if (map[p_my][p_mx - 1] == 'O'
		&& ply_x >= ((p_mx - 1) * TIL_SIZE) + 2)
		map[p_my][p_mx - 1] = 'D';
	if (map[p_my][p_mx + 1] == 'D')
		map[p_my][p_mx + 1] = 'O';
	else if (map[p_my][p_mx + 1] == 'O'
		&& ply_x + 2 <= ((p_mx + 1) * TIL_SIZE))
		map[p_my][p_mx + 1] = 'D';
	if (map[p_my - 1][p_mx] == 'D')
		map[p_my - 1][p_mx] = 'O';
	else if (map[p_my - 1][p_mx] == 'O'
		&& ply_y >= ((p_my - 1) * TIL_SIZE) + 2)
		map[p_my - 1][p_mx] = 'D';
	if (map[p_my + 1][p_mx] == 'D')
		map[p_my + 1][p_mx] = 'O';
	else if (map[p_my + 1][p_mx] == 'O'
		&& ply_y + 2 <= ((p_my + 1) * TIL_SIZE))
		map[p_my + 1][p_mx] = 'D';
}

void	open_dors(t_game *game)
{
	int	p_mx;
	int	p_my;

	p_mx = game->ply->p_x / TIL_SIZE;
	p_my = game->ply->p_y / TIL_SIZE;
	if (p_mx - 1 >= 0 && p_mx + 1 <= game->dt->map_h
		&& p_my - 1 >= 0 && p_my + 1 <= game->dt->map_w)
		change_map(game->dt->map2d, p_mx, p_my, game);
}
