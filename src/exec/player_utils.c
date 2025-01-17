/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:57:10 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/17 19:57:40 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	not_1D(char **map, int map_x, int map_y)
{
	if (map[map_y][map_x] != '1' && map[map_y][map_x] != 'D')
		return (1);
	return (0);
}
