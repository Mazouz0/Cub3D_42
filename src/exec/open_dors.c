/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:00:13 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/17 19:40:53 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"


void	change_map(char **map, int p_mx, int p_my)
{
	if (map[p_my][p_mx - 1] == 'D')
		map[p_my][p_mx - 1] = 'O';
	else if (map[p_my][p_mx - 1] == 'O')
		map[p_my][p_mx - 1] = 'D';
		
	if (map[p_my][p_mx + 1] == 'D')
		map[p_my][p_mx + 1] = 'O';
	else if (map[p_my][p_mx + 1] == 'O')
		map[p_my][p_mx + 1] = 'D';
		
	if (map[p_my - 1][p_mx] == 'D')
		map[p_my - 1][p_mx] = 'O';
	else if (map[p_my - 1][p_mx] == 'O')
		map[p_my - 1][p_mx] = 'D';
		
	if (map[p_my + 1][p_mx] == 'D')
		map[p_my + 1][p_mx] = 'O';
	else if (map[p_my + 1][p_mx] == 'O')
		map[p_my + 1][p_mx] = 'D';
}


void	open_dors(t_game *game)
{
	int	p_mx;
	int	p_my;
	char	**map;

	p_mx = game->ply->p_x / TIL_SIZE;
	p_my = game->ply->p_y / TIL_SIZE;
	map = game->dt->map2d;
	
	if (p_mx - 1 >= 0 && p_mx + 1 <= game->dt->map_h && p_my - 1 >= 0 && p_my + 1 <= game->dt->map_w)
	{
		// if (map[p_my][p_my] = '')
		// else
		change_map(map, p_mx, p_my);
	}
}
