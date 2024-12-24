/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:07:05 by alamini           #+#    #+#             */
/*   Updated: 2024/12/24 17:07:19 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/cube.h"

int main(int argc, char **argv)
{
	t_gdata *game;
	game = parsing(argc, argv);
	if (!game)
		return (1);
	view_map(game);
	printf("x = %d\n", game->map.player.x);
	printf("y = %d\n", game->map.player.y);
	printf("direction = %c\n", game->map.direction);
	return (0);
}