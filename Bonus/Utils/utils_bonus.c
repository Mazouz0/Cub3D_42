/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:50:24 by alamini           #+#    #+#             */
/*   Updated: 2025/01/21 18:31:33 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

char	*ex_strjoin(char	*s1, char	*s2)
{
	char	*res;
	int		length;

	if ((!s1 && !s2))
		return (NULL);
	else if (!s1)
		return (my_strdup(s2));
	else if (!s2)
	{
		res = my_strdup(s1);
		return (res);
	}
	length = ex_strlen(s1) + ex_strlen(s2);
	res = (char *)ft_malloc(sizeof(char) * length + 1, 0);
	if (!res)
		return (NULL);
	res = gnl_strcpy(s1, s2, res);
	return (res);
}

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
