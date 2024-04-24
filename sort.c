/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 03:06:55 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/24 03:27:14 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_correct_pos(t_node **a, int value, t_info *info)
{
	t_node	*tmp;
	int	j;
	int	closest;
	int	idx;

	j = 0;
	closest = INT32_MAX;
	idx = 0;
	tmp = (*a);
	info->nr = 0;
	info->nrr = 0;
	while (tmp)
	{
		if (tmp->element > value && tmp->element < closest)
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

void	sort(t_node **a, t_node **b, t_info *info)
{
	t_node *tmp;

	tmp = (*b);
	while (tmp)
	{
		set_correct_pos(a, tmp->element, info);
		while (info->nr > 0)
		{
			rotate(a);
			write(1, "ra\n", 3);
			info->nr--;
		}
		while (info->nrr > 0)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
			info->nrr--;
		}
		push_b(a, b, info);
		tmp = tmp->next;
	}
}
