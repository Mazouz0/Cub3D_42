/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:57:37 by alamini           #+#    #+#             */
/*   Updated: 2024/12/24 18:26:24 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int ft_error(char *errmsg)
{
	write(2, "Error\n", 6);
	write(2, errmsg, gnl_strlen(errmsg));
	write(2, "\n", 1);
	return (1);
}

int count_elements(char **dbl_arr)
{
	int i;

	if (!dbl_arr)
		return (0);	
	i = 0;
	while (dbl_arr[i])
		i++;
	return (i);
}

int in_set(char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void view_map(t_gdata *game)
{
	int i = 0;
	int j = 0;
	

	while (i < game->map.max_row)
	{
		j = 0;
		while (j < game->map.max_column)
		{
			printf("%c ", game->map.the_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}