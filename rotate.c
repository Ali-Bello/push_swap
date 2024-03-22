/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:06:09 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/22 10:02:41 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = (*a);
    (*a) = (*a)->next;
    tmp->next->next = 0;
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    t_stack *tmp;

    tmp = *b;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = (*b);
    (*b) = (*b)->next;
    tmp->next->next = 0;
    write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void    rra(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next)
    {
      if (!(tmp->next->next))
        break;
      tmp = tmp->next;
    }
    tmp->next->next = (*a);
    (*a) = tmp->next;
    tmp->next = 0;
    write(1, "rra\n", 4);
}

void    rrb(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next)
    {
      if (!(tmp->next->next))
        break;
      tmp = tmp->next;
    }
    tmp->next->next = (*a);
    (*a) = tmp->next;
    tmp->next = 0;
    write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
