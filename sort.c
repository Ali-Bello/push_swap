/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:53:56 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/15 23:46:23 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_stack(t_node **a,t_info *info)
{
	while (info->nr--)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	info->nr = 0;
}
void	sort(t_node **a, t_node **b, t_info *info)
{
	t_chunk *tmp;

	tmp = info->chunks;
	int	i;
	info->nr = 0;
	while (info->b_len > 2)
	{
		i = 0;
		printf("chunk_size = [%d]\n", tmp->chunk_size);
		t_node *tmp2 = *b;
		while (tmp2)
		{
			printf ("b -> [%d]\n", tmp2->element);
			tmp2 = tmp2->next;
		}
		while (i < tmp->chunk_size)
		{
			if ((*b)->element <= (*a)->element)
			{
				push_b(b, a, info);
				i++;
				write(1, "pa\n", 3);
			}
			else if (info->b_len > 2 && (*b)->next->element <= (*a)->next->element)
			{
					rr(a, b);
					push_b(b, a, info);
					i++;
					write(1, "pa\n", 3);
					rrr(a, b);
			}
			else
			{
				rotate(a);
				info->nr++;
				write(1, "ra\n", 3);
			}
		}
		if (info->nr)
			reset_stack(a, info);
		// printf("info->nr = [%d]\n", info->nr);
		tmp = tmp->next;
	}
}

