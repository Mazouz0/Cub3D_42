/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:44:20 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/13 00:59:41 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	*free_all(void **ptr_list, int *i)
{
	int	j;

	j = 0;
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
	void	*ptr;
	
	if (flag)
		return (free_all(ptr_list, &i));
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ptr_list[i++] = ptr;
	return (ptr);
		
}