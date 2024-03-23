/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 06:56:44 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/23 07:59:33 by aderraj          ###   ########.fr       */
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

void  add_node(t_stack **a, t_stack **new, t_info *info)
{
	t_stack *last;

	last = *a;
	while (last && last->next)
		last = last->next;
	if (!last)
		*a = *new;
	else
		last->next = *new;
	(*new)->next = 0;
	info->a_len++;
}

void	create_stack(t_stack **head, int len, t_info *info)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (i < len)
	{
		new = malloc(sizeof(t_stack));
		add_node(head, &new, info);
		i++;
	}
}
void	parse(int ac, char **av, t_stack **head, t_info *info)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	create_stack(head, ac, info);
	tmp = *head;
	while (av[i])
	{
		tmp->value = ft_atoi(av[i]);
		tmp = tmp->next;
		i++;
	}
}
void	free_stack(t_stack **head)
{
	t_stack *tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = 0;
}

