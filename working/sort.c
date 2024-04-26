/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:09:37 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/26 12:51:24 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *get_last(t_node *stack)
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

	sort_three(a, info);
	init_zero(info);
	while (info->b_len)
	{
		last = get_last(*a);
		while (last->value > (*b)->value && info->rra < 3)
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
