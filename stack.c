/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:15:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 17:15:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
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
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

void	fill_stack(t_node **top, char **av)
{
	t_node	*tmp;
	int	i;

	i = 1;
	tmp = *top;
	while (tmp)
	{
		tmp->element = ft_atoi(av[i]);
		tmp = tmp->next;
		i++;
	}
}

void	create_stack(t_node **top, t_info *info, int ac)
{
	t_node	*tmp;
	int	i;

    i = 0;
	while (i < ac)
	{
		tmp = malloc(sizeof(t_node));
		tmp->next = *top;
		(*top) = tmp;
		info->a_len++;
		i++;
	}
}
