/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:56:05 by aderraj           #+#    #+#             */
/*   Updated: 2024/05/01 22:08:25 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	stack = 0;
}

void	fill_stack(t_node **top, char **av)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *top;
	while (tmp)
	{
		tmp->value = ft_safe_atoi(av[i], av);
		tmp = tmp->next;
		i++;
	}
}

void	create_stack(t_node **top, t_info *info)
{
	t_node	*tmp;
	int		i;

	i = 0;
	while (i < info->a_len)
	{
		tmp = malloc(sizeof(t_node));
		if (!tmp)
		{
			free_stack(*top);
			return ;
		}
		tmp->next = *top;
		(*top) = tmp;
		i++;
	}
}
