/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:57:48 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/25 19:11:06 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_position(int value, t_node **b, t_info *info)
{
	t_node	*tmp;
	int	i;
	int	closest;
	int	idx;

	i = 0;
	closest = INT_MIN;
	idx = 0;
	tmp = (*b);
	while (tmp)
	{
		if (tmp->value < value && tmp->value > closest)
		{
			closest = tmp->value;
			idx = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (idx > info->b_len / 2)
		info->rrb = info->b_len - idx;
	else
		info->rb = idx;
}

void	set_a_rotations(int value, t_node **a, t_info *info)
{
	t_node	*tmp;
	int	idx;

	tmp = (*a);
	idx = 0;
	while (tmp)
	{
		if (tmp->value == value)
			break;
		idx++;
		tmp = tmp->next;
	}
	if (idx > info->a_len / 2)
		info->rra = info->a_len - idx;
	else
		info->ra = idx;
}

void	set_push_price(t_node **a, t_node **b, t_info *info)
{
	t_node	*tmp;

	tmp = (*a);
	while (tmp)
	{
		set_min_max(b, info);
		init_zero(info);
		if (tmp->value > info->max || tmp->value < info->min)
			bring_to_top(b, info);
		else if (tmp->value > info->min && tmp->value < info->max)
			find_position(tmp->value, b, info);
		set_a_rotations(tmp->value, a, info);
		tmp->info = *info;
		tmp = tmp->next;
	}
}

void	set_cheapest_moves(t_node **a, t_node **b, t_info *info)
{
	t_node	*tmp;
	int		min;


	tmp = *a;
	min = INT_MAX;
	set_push_price(a, b, info);
	reduce_price(a);
	while (tmp)
	{
		if (tmp->info.ra + tmp->info.rra + tmp->info.rb
			+ tmp->info.rrb + tmp->info.rr + tmp->info.rrr < min)
		{
			min = tmp->info.ra + tmp->info.rra + tmp->info.rb
				+ tmp->info.rrb + tmp->info.rr + tmp->info.rrr;
			info->ra = tmp->info.ra;
			info->rra = tmp->info.rra;
			info->rb = tmp->info.rb;
			info->rrb = tmp->info.rrb;
			info->rr = tmp->info.rr;
			info->rrr = tmp->info.rrr;
		}
		tmp = tmp->next;
	}
}
void	push_to_b(t_node **a, t_node **b, t_info *info)
{
	push(a, b, info, "pb\n");
	push(a, b, info, "pb\n");

	while (info->a_len > 3)
	{
		set_cheapest_moves(a, b, info);
		apply_moves(a, b, info);
		push(a, b, info, "pb\n");
	}
	init_zero(info);
	bring_to_top(b, info);
	apply_moves(a, b, info);
}
