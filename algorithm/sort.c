/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:09:37 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 23:38:20 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack, char *str)
{
	t_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (str)
		ft_putstr_fd(str, 1);
}

void	ss(t_node **a, t_node **b)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	swap(a, NULL);
	swap(b, NULL);
}

t_node	*get_last(t_node *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	sort_three(t_node **a, t_info *info)
{
	set_min_max(a, info);
	if ((*a)->next->value == info->max)
		swap(a, "sa\n");
	if ((*a)->value == info->max)
		rotate(a, "ra\n");
	if ((*a)->value > (*a)->next->value)
		swap(a, "sa\n");
}

void	sort(t_node **a, t_node **b, t_info *info)
{
	t_node	*last;
	int		limit;

	sort_three(a, info);
	init_zero(info);
	limit = info->a_len;
	while (info->b_len)
	{
		last = get_last(*a);
		while (last->value > (*b)->value && info->rra < limit)
		{
			reverse_rotate(a, "rra\n");
			info->rra++;
			last = get_last(*a);
		}
		push(b, a, info, "pa\n");
	}
	set_min_max(a, info);
	while ((*a)->value != info->min)
		reverse_rotate(a, "rra\n");
}
