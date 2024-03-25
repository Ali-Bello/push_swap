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
	t_stack	*tmp;

	tmp = *b;
	if (*b)
		*b = (*b)->next;
	else
		*b = 0;
	tmp->next = *a;
	*a = tmp;
	info->a_len++;
	info->b_len--;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_info *info)
{
	t_stack *tmp;

	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = 0;
	tmp->next = *b;
	tmp->prev = 0;
	*b = tmp;
	info->a_len--;
	info->b_len++;
	info->npb++;
  write(1, "pb\n", 3);
}
