/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:13 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/23 07:56:14 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_info *info)
{
    t_stack *tmp;

    if (*b)
    {
        tmp = *b;
        *b = (*b)->next;
        if (*b)
            (*b)->prev = 0;
        tmp->next = *a;
        if (*a)
            (*a)->prev = tmp;
        tmp->prev = 0;
        *a = tmp;
        info->a_len++;
        info->b_len--;
    }
    write(1, "pa\n", 3);
}


void	pb(t_stack **a, t_stack **b, t_info *info)
{
	t_stack *tmp;

	tmp = *a; //points to the node we're moving
	*a = (*a)->next; //make a point to the next node;

	(*a)->prev = 0;// a prev is now null (it's the first node)
	tmp->next = *b;// make the new node ->next points to the first node of b
	tmp->prev = 0;//make the new node ->prev = 0 because it's the first node now;
	if (*b)
		(*b)->prev = tmp;// if there is a node make it's prev points to the new node;
	*b = tmp; // b now points to the new node;
	info->a_len--;
	info->b_len++;
	info->npb++;
  write(1, "pb\n", 3);
}
