/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 03:06:55 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/25 19:24:05 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a, t_node **b, t_info *info)
{
	t_node *last;

	info->nr = 0;
	last = get_last(*a);
	while (info->b_len)
	{
		while (last->element > (*b)->element && info->nr < 3)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
			info->nr++;
			last = get_last(*a);
		}
		push_b(b, a, info);
	}
}

void	sort_three(t_node **a)
{
	if ((*a)->element > (*a)->next->element
		&& (*a)->element > (*a)->next->next->element)
	{
		rotate(a);
		write(1, "ra\n", 3);
		sort_three(a);
	}
	else if ((*a)->element > (*a)->next->element
		&& (*a)->element < (*a)->next->next->element)
	{
		swap(a);
		write(1, "sa\n", 3);
		sort_three(a);
	}
	else if ((*a)->element <  (*a)->next->element
			&& (*a)->next->element > (*a)->next->next->element)
	{
		swap(a);
		write(1, "sa\n", 3);
		sort_three(a);
	}
}
