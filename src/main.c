/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:07:05 by alamini           #+#    #+#             */
/*   Updated: 2025/01/01 03:15:30 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/cube.h"

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
}