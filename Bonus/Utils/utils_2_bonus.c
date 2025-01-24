/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:44:20 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/23 20:54:29 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

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
			if (game->dt->txtr->door)
				mlx_delete_texture(game->dt->txtr->door);
		}
	}
	ft_malloc(0, 1);
	exit(exit_status);
}

void	*free_all(void **ptr_list, int *i)
{
	int	j;

	j = 0;
	if (!ptr_list || (*i) == 0)
		return (NULL);
	while (ptr_list[j])
	{
		free(ptr_list[j]);
		ptr_list[j] = NULL;
		j++;
	}
	*i = 0;
	return (NULL);
}

void	*ft_malloc(ssize_t size, int flag)
{
	static void	*ptr_list[INT_MAX];
	static int	i;
	void		*ptr;

	if (flag)
		return (free_all(ptr_list, &i));
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ptr_list[i++] = ptr;
	return (ptr);
}

void	delete_texture(t_texture *txtr)
{
	if (txtr->no)
		mlx_delete_texture(txtr->no);
	if (txtr->so)
		mlx_delete_texture(txtr->so);
	if (txtr->we)
		mlx_delete_texture(txtr->we);
	if (txtr->ea)
		mlx_delete_texture(txtr->ea);
	if (txtr->door)
		mlx_delete_texture(txtr->door);
	ft_clean(NULL, "Texture failed");
}
