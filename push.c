/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:13 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/22 08:23:05 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	(*a)->len++;
	(*b)->len--;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
  t_stack *tmp;

  tmp = *a;
  *a = (*a)->next;
  tmp->next = *b;
  *b = tmp;
	(*a)->len--;
	(*b)->len++;
	(*b)->npb++;
  write(1, "pb\n", 3);
}
