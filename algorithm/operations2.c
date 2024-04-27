/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:53:30 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 06:46:10 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack, char *str)
{
	t_node	*tmp;

	if (!*stack)
		return ;
	tmp = (*stack)->next;

	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;

	if (str)
		ft_putstr_fd(str, 1);
}

void	ss(t_node **a, t_node **b)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	swap(a, NULL);
	swap(b, NULL);
}
