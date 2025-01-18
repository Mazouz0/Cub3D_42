/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:07:05 by alamini           #+#    #+#             */
/*   Updated: 2025/01/18 13:33:13 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

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
<<<<<<< HEAD
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		game->ply->rot = -1;
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		game->ply->rot = 1;
	if (key_data.key == MLX_KEY_E && key_data.action == MLX_PRESS)
		game->gun = 1;
=======
>>>>>>> dd9fba52c866fd7f7c8a37387eda5a51625004ad
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_PRESS)
		open_dors(game);
	ft_reles(key_data, game);
}

void	mouse_hook(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		game->gun = 1;
}

void	cursor_func(double xpos, double ypos, void *param)
{
	t_game	*game;
	double	delta;

	(void)ypos;
	game = (t_game *)param;
	if (game->last_x == -1)
		game->last_x = xpos;
	delta = xpos - game->last_x;
	game->ply->angle_dir += delta * ROT_SPEED * 0.01;
	game->last_x = xpos;
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
	mlx_mouse_hook(game->mlx, mouse_hook, game);
	mlx_cursor_hook(game->mlx, cursor_func, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	mlx_loop(game->mlx);
	ft_clean(game, NULL);
	return (0);
}
