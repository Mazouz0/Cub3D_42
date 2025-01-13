/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:07:05 by alamini           #+#    #+#             */
/*   Updated: 2025/01/13 01:01:36 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/cube.h"

void	ft_clean(t_game *game, char *msg)
{
	if (msg)
		printf("%s\n", msg);
	
	ft_malloc(0, 1);
	exit(0);
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
		game->ply->l_r = -1, printf("left => %d\n", game->ply->l_r);
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
		game->ply->l_r = 1, printf("right => %d\n", game->ply->l_r);
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
		game->ply->u_d = -1, printf("down => %d\n", game->ply->u_d);
	else if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		game->ply->u_d = 1, printf("up => %d\n", game->ply->u_d);
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		game->ply->rot = -1, printf("rotate left => %d\n", game->ply->rot);
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		game->ply->rot = 1, printf("rotate right => %d\n", game->ply->rot);
	ft_reles(key_data, game);
		
}

int	main(int argc, char **argv)
{
	t_gdata	*pars_data;
	t_game	*game;
	
	pars_data = parsing(argc, argv);
	if (!pars_data)
		return (1);
	game = init_game(pars_data);
	if (!game)
		return (ft_error("Game initialization failed"));
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	ft_clean(game, NULL);
	return (0);
}
