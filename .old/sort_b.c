/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:24:39 by marvin            #+#    #+#             */
/*   Updated: 2024/03/29 16:24:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculate the median value of the chunk
// calculate the median value of the elements bigger than the chunk * repeat this step until you find the biggest number in the chunk
// reverse rotate the rotations 

void	best_bmove(t_stack **stack, t_info *info, int n)
{
	t_stack	*tmp, *last;


	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	while (tmp->value != info->array[n])
	{
		info->nr++;
		tmp = tmp->next;
	}
	while (info->nr && last->value != info->array[n])
	{
		info->nrr++;
		last = last->prev;
	}
}
void    ft_sort_b(t_stack **a, t_stack **b, t_info *info)
{
    int max_idx = info->b_len - 1;
    t_stack *tmp = *b;
    while (info->b_len > 1)
    {
        info->nr = 0;
        info->nrr = 0;
        best_bmove(b, info, max_idx--);
        if (info->nr <= info->nrr)
        {
            while (info->nr--)
                rb(b);
            pa(a, b, info);
        }
        else
        {
            while (info->nrr--)
                rrb(b);
            pa(a, b, info);
        }
    }
    pa(a, b, info);
    //if the value we are pushing is bigger than the top, push it right away;
    //else rotate until you find something smaller than the value;
}