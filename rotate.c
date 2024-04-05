/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:06:09 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/23 07:57:28 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack **a)
{
    t_stack *tmp;

    tmp = get_last(*a);

    tmp->next = (*a);// make the lastNode ->next points to the firstnode
    
    (*a)->prev = tmp;// make the firstNode->prev points to the lastnode

    (*a) = (*a)->next;// make a points to the second node;
    
    (*a)->prev = 0;//make the secondNode->prev points to 0

    tmp->next->next = 0; // make the last next pointer points to 0
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    t_stack *tmp;

    tmp = get_last(*b);

    tmp->next = (*b);
    (*b)->prev = tmp;
  
    (*b) = (*b)->next;
    (*b)->prev = 0;

    tmp->next->next = 0;
    write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
    write(1, "rr\n", 1);
}

void    rra(t_stack **a)
{
    t_stack *tmp;

    tmp = get_last(*a);
  
    tmp->next= (*a);
    (*a)->prev = tmp;
  
    (*a) = tmp;
  
    tmp->prev->next = 0;
    tmp->prev = 0;
    write(1, "rra\n", 4);
}

void    rrb(t_stack **b)
{
    t_stack *tmp;

    tmp = get_last(*b);

    tmp->next = (*b);
    (*b)->prev = tmp;
  
    (*b) = tmp;
    tmp->prev->next = 0;
    tmp->prev = 0;
    write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
