/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:10:10 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 23:43:45 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithm/push_swap.h"
#include "libft.h"

void	ft_error(char **args)
{
	free_args(args);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int	ft_safe_atoi(const char *str, char **args)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		++i;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign * result) > INT_MAX || (sign * result) < INT_MIN)
			ft_error(args);
		i++;
	}
	return ((int)(result * sign));
}
