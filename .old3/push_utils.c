/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:01:51 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/24 19:39:18 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void	set_max_min(t_node **b, t_info *info)
{
	t_node *tmp;
	int	min;
	int	max;

	tmp = (*b);
	min = (*b)->element;
	max = (*b)->element;
	while (tmp)
	{
		if (tmp->element < min)
			min = tmp->element;
		if (tmp->element > max)
			max = tmp->element;
		tmp = tmp->next;
	}
	info->b_min = min;
	info->b_max = max;
}

void	bring_max(t_node **stack, t_info *info)
{
	int	i, j;
	t_node	*last;
	t_node	*first;

	first = *stack;
	last = get_last(*stack);
	i = 0;
	while (first && first->element != info->b_max)
	{
		first = first->next;
		i++;
	}
	j = 1;
	while (last && last->element != info->b_max)
	{
		last = last->prev;
		j++;
	}
	if (i > j)
		info->nrr = j;
	else
		info->nr = i;
}

void	apply_moves(t_node **a, t_node **b, t_info *info)
{
	while (info->rr-- > 0)
		rr(a, b);
	while (info->rrr-- > 0)
		rrr(a, b);
	while (info->a_r > 0)
	{
		rotate(a);
		write(1, "ra\n", 3);
		info->a_r--;
	}
	while (info->a_rr > 0)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		info->a_rr--;
	}
	while (info->b_r > 0)
	{
		rotate(b);
		write(1, "rb\n", 3);
		info->b_r--;
	}
	while (info->b_rr > 0)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
		info->b_rr--;
	}
}
void	find_insert_pos(int value, t_node **b, t_info *info)
{
	t_node	*tmp;
	int	j;
	int	closest;
	int	idx;

	j = 0;
	closest = INT32_MIN;
	idx = 0;
	tmp = (*b);
	while (tmp)
	{
		if (tmp->element < value && tmp->element > closest)
		{
			closest = tmp->element;
			idx = j;
		}
		j++;
		tmp = tmp->next;
	}
	if (idx > info->b_len / 2)
		info->nrr = info->b_len - idx;
	else
		info->nr = idx;
}
