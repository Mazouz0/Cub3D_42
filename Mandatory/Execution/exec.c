/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:44:55 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/23 21:11:11 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_usleep(unsigned int microseconds)
{
	struct timeval	start;
	struct timeval	current;
	double			elapsed;
	double			target_seconds;

	elapsed = 0.0;
	target_seconds = microseconds / 1000000.0;
	gettimeofday(&start, NULL);
	while (elapsed < target_seconds)
	{
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start.tv_sec)
			+ (current.tv_usec - start.tv_usec) / 1000000.0;
	}
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIND_WID, WIND_HEI);
	player_hook(game, 0, 0);
	draw_map(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	ft_usleep(12000);
}
