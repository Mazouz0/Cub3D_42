/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:49:00 by alamini           #+#    #+#             */
/*   Updated: 2025/01/13 02:06:11 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*left_overs(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	if (!str || !gnl_strchr(str, '\n'))
		return (free(str), NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (gnl_strlen(str) - 1 == i)
		return (free(str), NULL);
	result = (char *)malloc(sizeof(char) * (gnl_strlen(str) - i));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

static char	*main_line(char *str)
{
	int		i;
	int		j;
	char	*result;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	result = malloc(sizeof(char) * i + 2);
	if (!result)
		return (free(str), NULL);
	j = 0;
	while (j < i + 1)
	{
		result[j] = str[j];
		j++;
	}
	result[i + 1] = '\0';
	return (result);
}

static char	*read_to_buffer(int fd, char *buffer, int *read_count)
{
	*read_count = read(fd, buffer, BUFFER_SIZE);
	buffer[*read_count] = '\0';
	if (*read_count == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*buffer;
	char		*line;
	int			read_count;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (free(result), result = NULL, NULL);
	buffer = (char *)malloc((unsigned int)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(result), result = NULL, NULL);
	read_count = 0;
	while (1)
	{
		buffer = read_to_buffer(fd, buffer, &read_count);
		result = gnl_strjoin(result, buffer);
		if (gnl_strchr(buffer, '\n') || read_count == 0)
		{
			line = main_line(result);
			result = left_overs(result);
			break ;
		}
	}
	return (free(buffer), line);
}
