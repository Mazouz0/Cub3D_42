/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:57:41 by mohmazou          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:38 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

static	int	handle_over_flow(long number, const char *index, int sign)
{
	if (sign > 0)
	{
		if (*index - 48 >= 7 || number > 922337203685477580)
			return (-1);
	}
	else if (sign < 0)
	{
		if (*index - 48 >= 9 || number > 922337203685477580)
			return (-1);
	}
	number = number * 10 + *index - 48;
	return (number * sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		if (result >= 922337203685477580 && str[i + 1])
			return (handle_over_flow(result, &str[i + 1], sign));
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*my_strdup(const char *s1)
{
	char	*ptr;
	int		size;
	int		i;

	if (!s1)
		return (NULL);
	size = ex_strlen(s1);
	ptr = ft_malloc((sizeof(char) * (size + 1)), 0);
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
