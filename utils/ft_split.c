/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:46:14 by alamini           #+#    #+#             */
/*   Updated: 2025/01/13 01:28:14 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

static int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

static char	*get_word(const char *s1, int *index, char c)
{
	char	*copy;
	size_t	word_len;
	int		i;

	word_len = 0;
	while (s1[*index] == c)
		(*index)++;
	i = *index;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	copy = ft_malloc(sizeof(char) * (word_len + 1), 0);
	if (!copy)
		return (ft_clean(NULL, "Allocation Error"), NULL);
	i = 0;
	while (s1[*index] && s1[*index] != c)
		copy[i++] = s1[(*index)++];
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		index;
	int		wc;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = word_count(s, c);
	arr = ft_malloc(sizeof(char *) * (wc + 1), 0);
	if (!arr)
		return (ft_clean(NULL, "Allocation Error"), NULL);
	while (i < wc)
	{
		arr[i] = get_word(s, &index, c);
		if (!arr[i])
			return (ft_clean(NULL, "Allocation Error"), NULL);
		i++;
	}
	arr[i] = 0;
	return (arr);
}