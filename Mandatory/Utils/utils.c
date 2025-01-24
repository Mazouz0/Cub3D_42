/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:50:24 by alamini           #+#    #+#             */
/*   Updated: 2025/01/23 20:56:21 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ex_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

size_t	ex_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
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
	ft_clean(NULL, "Texture failed");
}
