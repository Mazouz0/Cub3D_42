/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:44:20 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/16 17:56:23 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

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

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*ret;
	const char	*digits = "0123456789";

	len = ft_numlen(n, 10);
	ret = ft_malloc(sizeof(char) * (len + 1), 0);
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (ret);
}