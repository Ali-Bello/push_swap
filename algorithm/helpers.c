/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:57:23 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 23:23:30 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_node **stack, t_info *info)
{
	t_node	*tmp;
	int		idx;

	idx = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == info->max)
			break ;
		idx++;
		tmp = tmp->next;
	}
	if (idx > info->b_len / 2)
		info->rrb = info->b_len - idx;
	else
		info->rb = idx;
}

void	set_min_max(t_node **stack, t_info *info)
{
	t_node	*tmp;
	int		max;
	int		min;

	if (!*stack)
		return ;
	tmp = *stack;
	max = (*stack)->value;
	min = (*stack)->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		else if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	info->max = max;
	info->min = min;
}

void	init_zero(t_info *info)
{
	info->ra = 0;
	info->rra = 0;
	info->rb = 0;
	info->rrb = 0;
	info->rr = 0;
	info->rrr = 0;
}

void	apply_moves(t_node **a, t_node **b, t_info *info)
{
	while (info->rr-- > 0)
		rr(a, b, "rr");
	while (info->rrr-- > 0)
		rrr(a, b, "rrr");
	while (info->ra-- > 0)
		rotate(a, "ra\n");
	while (info->rra-- > 0)
		reverse_rotate(a, "rra\n");
	while (info->rb-- > 0)
		rotate(b, "rb\n");
	while (info->rrb-- > 0)
		reverse_rotate(b, "rrb\n");
}

void	reduce_price(t_node **a)
{
	t_node	*tmp;

	tmp = (*a);
	while (tmp)
	{
		while (tmp->info.ra > 0 && tmp->info.rb > 0)
		{
			tmp->info.rr++;
			tmp->info.ra--;
			tmp->info.rb--;
		}
		while (tmp->info.rra > 0 && tmp->info.rrb > 0)
		{
			tmp->info.rrr++;
			tmp->info.rra--;
			tmp->info.rrb--;
		}
		tmp = tmp->next;
	}
}
