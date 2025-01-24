/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:44:55 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 20:37:42 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

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

void	draw_4pxl(t_game *game, int i, int j)
{
	put_pixel(game->img, i, j, game->dt->c_clr);
	put_pixel(game->img, WIND_WID - i, j, game->dt->c_clr);
	put_pixel(game->img, i, WIND_HEI - j, game->dt->f_clr);
	put_pixel(game->img, WIND_WID - i, WIND_HEI - j, game->dt->f_clr);
}

void	draw_bg(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIND_WID / 2)
	{
		j = 0;
		while (j < WIND_HEI / 2)
		{
			draw_4pxl(game, i, j);
			j += 2;
		}
		i += 2;
	}
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIND_WID, WIND_HEI);
	if (game->cursor)
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	else
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	player_hook(game, 0, 0);
	draw_map(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	ft_usleep(12000);
}
