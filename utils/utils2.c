/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:01:04 by alamini           #+#    #+#             */
/*   Updated: 2024/12/05 23:01:16 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

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