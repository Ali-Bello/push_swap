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
	t_node	*tmp;
	t_node	*last;

	tmp = *top;
	last = get_last(*top);

	last->next = tmp;
	tmp->prev = last;

	(*top) = (*top)->next;
	(*top)->prev = 0;

	tmp->next = 0;
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_node **top)
{
	t_node	*last;

	last = get_last(*top);

	last->prev->next = 0;
	last->prev = 0;
	last->next = (*top);

	(*top)->prev = last;
	(*top) = last;
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	swap(t_node **top)
{
	t_node	*tmp;

	tmp = *top;

	(*top) = (*top)->next;

	tmp->next = (*top)->next;
	if (tmp->next)
		(*top)->next->prev = tmp;
	(*top)->next = tmp;

	(*top)->prev = 0;

}

void	push(t_node	**a, t_node	**b, t_info *info)
{
	t_node	*tmp;

	tmp = *a;

	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;

	tmp->next = (*b);
	if (*b)
		(*b)->prev = tmp;
	(*b) = tmp;
	info->a_len--;
	info->b_len++;
}
void	push_b(t_node	**a, t_node	**b, t_info *info)
{
	t_node	*tmp;

	tmp = *a;

	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;

	tmp->next = (*b);
	if (*b)
		(*b)->prev = tmp;

	(*b) = tmp;
	info->a_len++;
	info->b_len--;
}
