/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:09:22 by marvin            #+#    #+#             */
/*   Updated: 2024/04/11 15:09:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *get_last(t_node *stack)
{
    while (stack && stack->next)
        stack = stack->next;
    return (stack);
}

void	rotate(t_node **top)
{
    t_node  *tmp;
    t_node  *last;

    tmp = *top;
    last = get_last(*top);
    (*top) = (*top)->next;
    last->next = tmp;
    tmp->next = 0;
}

void	rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void    reverse_rotate(t_node **top)
{
    t_node  *pre_last;
    t_node  *tmp;

    pre_last = *top;
    // get node before last
    while (pre_last->next->next)
        pre_last = pre_last->next;

    tmp = pre_last->next;
    tmp->next = *top;
    *top = tmp;
    pre_last->next = 0;
}

void	rrr(t_node **a, t_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}

void	swap(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	push(t_node	**a, t_node	**b, t_info *info)
{
	t_node	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
    info->a_len--;
    info->b_len++;
}
void	push_b(t_node	**a, t_node	**b, t_info *info)
{
	t_node	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
    info->a_len++;
    info->b_len--;
}
