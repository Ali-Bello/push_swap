/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:06 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/20 13:36:45 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack	**a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = tmp->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	sb(t_stack	**b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = tmp->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
