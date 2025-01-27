/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:54:25 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 18:00:03 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	print_message(char *msg)
{
	int	exit_status;

	exit_status = ex_strcmp("Game over\n", msg);
	if (exit_status)
	{
		printf("Error\n");
		exit_status = 1;
	}
	if (msg)
		printf("\t%s\n", msg);
	return (exit_status);
}

void	ft_clean(t_game *game, char *msg)
{
	int	exit_status;

	exit_status = print_message(msg);
	if (game)
	{
		if (game->mlx)
			mlx_terminate(game->mlx);
		if (game->img)
			mlx_delete_image(game->mlx, game->img);
		if (game->dt && game->dt->txtr)
		{
			if (game->dt->txtr->no)
				mlx_delete_texture(game->dt->txtr->no);
			if (game->dt->txtr->ea)
				mlx_delete_texture(game->dt->txtr->ea);
			if (game->dt->txtr->so)
				mlx_delete_texture(game->dt->txtr->so);
			if (game->dt->txtr->we)
				mlx_delete_texture(game->dt->txtr->we);
		}
	}
	ft_malloc(0, 1);
	exit(exit_status);
}

void	ft_reles(mlx_key_data_t key_data, t_game *game)
{
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
		game->ply->l_r = 0;
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
		game->ply->l_r = 0;
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
		game->ply->u_d = 0;
	else if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
		game->ply->u_d = 0;
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_RELEASE)
		game->ply->rot = 0;
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_RELEASE)
		game->ply->rot = 0;
}

void	key_hook(mlx_key_data_t key_data, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_data.key == MLX_KEY_ESCAPE)
		ft_clean(game, "Game over\n");
	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
		game->ply->l_r = -1;
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
		game->ply->l_r = 1;
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
		game->ply->u_d = -1;
	else if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		game->ply->u_d = 1;
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		game->ply->rot = -1;
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		game->ply->rot = 1;
	ft_reles(key_data, game);
}

int	main(int argc, char **argv)
{
	t_gdata	*pars_data;
	t_game	*game;

	pars_data = parsing(argc, argv);
	if (!pars_data)
		return (ft_clean(NULL, "Parsing failed"), 1);
	game = init_game(pars_data);
	if (!game)
		return (ft_clean(NULL, "Game initialization failed"), 1);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	ft_clean(game, "Game over\n");
	return (0);
}
