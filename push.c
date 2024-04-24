/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:05:48 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/24 00:00:31 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_a_rotations(t_node **stack, int value, t_info *info)
{
	t_node	*tmp;
	int	idx;

	tmp = (*stack);
	idx = 0;
	info->a_r = 0;
	info->a_rr = 0;
	while (tmp)
	{
		if (tmp->element == value)
			break;
		idx++;
		tmp = tmp->next;
	}
	if (idx > info->a_len / 2)
		info->a_rr = info->a_len - idx;
	else
		info->a_r = idx;
}

void	reduce_price(t_node **a)
{
	t_node *tmp;

	tmp = (*a);
	while (tmp)
	{
		tmp->rr = 0;
		tmp->rrr = 0;
		while (tmp->a_r > 0 && tmp->b_r > 0)
		{
			tmp->rr++;
			tmp->a_r--;
			tmp->b_r--;
		}
		while (tmp->a_rr > 0 && tmp->b_rr > 0)
		{
			tmp->rrr++;
			tmp->a_rr--;
			tmp->b_rr--;
		}
		tmp = tmp->next;
	}
}
void	set_push_price(t_node **a, t_node **b, t_info *info)
{
	t_node	*tmp_b;
	t_node	*tmp_a;
	int	i;

	tmp_b = (*b);
	tmp_a = (*a);
	i = 0;
	while (tmp_a)
	{
		info->nr = 0;
		info->nrr = 0;
		if (tmp_a->element > info->b_max || tmp_a->element < info->b_min)
		{
			bring_max(b, info);
			tmp_a->b_r = info->nr;
			tmp_a->b_rr = info->nrr;
			if (tmp_a->element > info->b_max)
				tmp_a->is_max = 1;
		}
		else if (tmp_a->element > info->b_min && tmp_a->element < info->b_max)
		{
			find_insert_pos(tmp_a->element, b, info);
			tmp_a->b_r = info->nr;
			tmp_a->b_rr = info->nrr;
		}
		best_a_rotations(a, tmp_a->element, info);
		tmp_a->a_r = info->a_r;
		tmp_a->a_rr = info->a_rr;
		tmp_a = tmp_a->next;
	}
}

void	find_cheapest_moves(t_node **a, t_info *info)
{
	t_node	*tmp;
	int	min;
	tmp = *a;
	min = INT32_MAX;
	while (tmp)
	{
		if (tmp->a_r + tmp->a_rr + tmp->b_r + tmp->b_rr + tmp->rr + tmp->rrr < min)
		{
			min = tmp->a_r + tmp->a_rr + tmp->b_r + tmp->b_rr + tmp->rr + tmp->rrr;
			// printf("min = [%d]\n", min);
			// printf("min elem = [%d]\n", tmp->element);
			info->a_r = tmp->a_r;
			info->a_rr = tmp->a_rr;
			info->b_r = tmp->b_r;
			info->b_rr = tmp->b_rr;
			info->rr = tmp->rr;
			info->rrr = tmp->rrr;
		}
		tmp = tmp->next;
	}
}

void	push_everything(t_node **a, t_node **b, t_info *info)
{
	int i;

	i = 0;
	while (i++ < 2)
		push(a, b, info);
	info->b_max = (*b)->element * ((*b)->element > (*b)->next->element)
					+ (*b)->next->element * ((*b)->element < (*b)->next->element);
	info->b_min = (*b)->next->element * ((*b)->element > (*b)->next->element)
					+ (*b)->element * ((*b)->element < (*b)->next->element);
	while (info->a_len > 3)
	{
		set_push_price(a, b, info);
		reduce_price(a);
		t_node *tmp;
		tmp = (*a);
		while (tmp)
		{
			// printf("a -> [%d]\t a->a_r = [%d]\t a->a_rr = [%d]\t a->b_r = [%d]\ta->b_rr = [%d] a->rr = [%d]\t a->rrr = [%d]\n", tmp->element, tmp->a_r, tmp->a_rr, tmp->b_r, tmp->b_rr, tmp->rr, tmp->rrr);
			tmp = tmp->next;
		}
		find_cheapest_moves(a, info);
		apply_moves(a, b, info);
		push(a, b, info);
		set_max_min(b, info);
	}
}
