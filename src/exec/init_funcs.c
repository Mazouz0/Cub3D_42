/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 02:58:51 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/07 23:24:51 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

t_texture	*init_texture(t_gdata *pars_data)
{
	t_texture	*txtr;

	txtr = malloc(sizeof(t_texture));
	if (!txtr)
		return (NULL);
	txtr->no = mlx_load_png(pars_data->north);
	txtr->so = mlx_load_png(pars_data->south);
	txtr->we = mlx_load_png(pars_data->west);
	txtr->ea = mlx_load_png(pars_data->east);
	if (!txtr->no || !txtr->so || !txtr->we || !txtr->ea)
		return (NULL);
	return (txtr);
}

t_data	*init_ex_data(t_gdata *pars_data)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (NULL);
	data->map2d = pars_data->map.the_map;
	data->map_w = pars_data->map.max_column;
	data->map_h = pars_data->map.max_row;
	data->f_clr = pars_data->floor;
	data->c_clr = pars_data->ceiling;
	data->txtr = init_texture(pars_data);
	if (!data->txtr)
		return (NULL);
	return (data);
}

t_player	*init_player(t_gdata *pars_data)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		return (NULL);
	player->p_x = pars_data->map.player.x * TIL_SIZE + TIL_SIZE / 2;
	player->p_y = pars_data->map.player.y * TIL_SIZE + TIL_SIZE / 2;
	player->angle_dir = pars_data->map.direction * (M_PI / 2);
	player->fov_rd = (FOV * (M_PI / 180));
	return (player);
}

void	set_dist(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIND_WID)
	{
		game->rays_dist[i] = TIL_SIZE;
		i++;
	}
}

t_game	*init_game(t_gdata *pars_data)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);
	game->mlx = mlx_init(WIND_WID, WIND_HEI, "Cub3D", false);
	if (!game->mlx)
		return (NULL);
	game->img = mlx_new_image(game->mlx, WIND_WID, WIND_HEI);
	if (!game->img)
		return (NULL);
	game->dt = init_ex_data(pars_data);
	game->ply = init_player(pars_data);
	game->ray = (t_ray *)ft_calloc(sizeof(t_ray), 1);
	if (!game->dt || !game->ply || !game->ray)
		return (NULL);
	set_dist(game);
	return (game);
}
