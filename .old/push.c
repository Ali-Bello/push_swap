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
t_stack *get_last(t_stack *stack)
{
    if (stack)
    {
        while (stack->next)
            stack = stack->next;
    }
    return (stack);
}

void	pa(t_stack **a, t_stack **b, t_info *info)
{
	t_stack *tmp, *tmp2;


    tmp = get_last(*a); //last node of a
    tmp2 = get_last(*b); //last node of b

    if (tmp)
        tmp->next = tmp2; //last_a -> next points to last_b;
    else
        *b = tmp2;
    tmp2->prev->next = 0; //new last_b -> points to null
    tmp2->prev = tmp; // new node_prev -> last_a

	info->a_len--;
	info->b_len++;
    write(1, "pa\n", 3);
}


void	pb(t_stack **a, t_stack **b, t_info *info)
{
	t_stack *tmp, *tmp2;


    tmp = get_last(*b); //last node of b
    tmp2 = get_last(*a); //last node of a

    if (tmp)
        tmp->next = tmp2; //last_b -> next points to last_a;
    else
        *b = tmp2;
    tmp2->prev->next = 0; //new last_a -> points to null
    tmp2->prev = tmp; // new node_prev -> last_b

	info->a_len--;
	info->b_len++;
	info->npb++;
  write(1, "pb\n", 3);
}
