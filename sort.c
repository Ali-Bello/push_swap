/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:53:56 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/16 07:23:50 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a, t_node **b, t_info *info)
{
	t_chunk *tmp;
	t_node	*last;

	tmp = info->chunks;
	int	i;
	while (info->b_len && tmp)
	{
		i = 0;
		info->nr = 0;
		while (info->b_len && i < tmp->chunk_size)
		{
			// if ((*b)->element == 0)
			// {
			// 	printf ("|||||||||||||LOOK HERE|||||||||||||");
			// 	t_node *tmp3 = (*b);
			// 	while (tmp3)
			// 	{
			// 		printf("b-> [%d]\n", tmp3->element);
			// 		tmp3 = tmp3->next;
			// 	}
			// 	printf (" ------------- \n");
			// 	tmp3 = (*a);
			// 	while (tmp3)
			// 	{
			// 		printf("a-> [%d]\n", tmp3->element);
			// 		tmp3 = tmp3->next;
			// 	}
			// }
			if ((*b)->element <= (*a)->element)
			{
				push_b(b, a, info);
				i++;
				write(1, "pa\n", 3);
				last = get_last(*a);
				if (info->nr > 0)
				{
					while((*b) && last->element > (*b)->element && info->nr-- > 0)
					{
						reverse_rotate(a);
						write(1, "rra\n", 4);
						last = get_last(*a);
					}
				}
			}
			else
			{
				rotate(a);
				info->nr++;
				write(1, "ra\n", 3);
			}
		}
		tmp = tmp->next;
	}
	// while (info->nr--)
	// {
	// 	reverse_rotate(a);
	// 	write(1, "rra\n", 4);
	// }
}

