/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:49:07 by alamini           #+#    #+#             */
/*   Updated: 2024/12/23 21:08:51 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(char *s1)
{
	char	*ptr;
	int		size;
	int		i;

	size = gnl_strlen(s1);
	ptr = malloc((sizeof(char) * (size + 1)));
	if (!ptr)
		return (0);
	i = 0;
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)s + gnl_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char	*s1, char	*s2)
{
	char	*res;
	int		length;

	if ((!s1 && !s2))
		return (NULL);
	else if (!s1)
		return (gnl_strdup(s2));
	else if (!s2)
	{
		res = gnl_strdup(s1);
		return (free(s1), res);
	}
	length = gnl_strlen(s1) + gnl_strlen(s2);
	res = (char *)malloc(sizeof(char) * length + 1);
	if (!res)
		return (free(s1), NULL);
	res = gnl_strcpy(s1, s2, res);
	free(s1);
	return (res);
}

void	*gnl_strcpy(char *s1, char *s2, char *res)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
//kkkkkk