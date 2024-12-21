/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:50:24 by alamini           #+#    #+#             */
/*   Updated: 2024/12/16 23:00:14 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

char	*ex_strjoin(char	*s1, char	*s2)
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
		return (res);
	}
	length = gnl_strlen(s1) + gnl_strlen(s2);
	res = (char *)malloc(sizeof(char) * length + 1);
	if (!res)
		return (NULL);
	res = gnl_strcpy(s1, s2, res);
	return (res);
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

int ft_error(char *errmsg)
{
	write(2, "Error\n", 6);
	write(2, errmsg, gnl_strlen(errmsg));
	write(2, "\n", 1);
	return (1);
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

char	*ex_strdup(const char *s1)
{
	char	*ptr;
	int		size;
	int		i;

	size = ex_strlen(s1);
	ptr = malloc((sizeof(char) * (size + 1)));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int is_number(char *number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (1);
		i++;
	}
	return (0);
}
