/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:57:10 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:09 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

int	not_1d(char **map, int map_x, int map_y)
{
	if (map[map_y][map_x] != '1' && map[map_y][map_x] != 'D')
		return (1);
	return (0);
}
