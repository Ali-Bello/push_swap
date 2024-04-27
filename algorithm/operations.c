/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:58:49 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 23:24:19 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack, char *str)
{
	t_node	*tmp;
	t_node	*new_top;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	new_top = (*stack)->next;
	(*stack)->next = 0;
	tmp->next = (*stack);
	(*stack) = new_top;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rr(t_node **a, t_node **b, char *str)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	rotate(a, NULL);
	rotate(b, NULL);
	if (str)
		write(1, "rr\n", 3);
}

void	reverse_rotate(t_node **stack, char *str)
{
	t_node	*tmp;
	t_node	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rrr(t_node **a, t_node **b, char *str)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	if (str)
		write(1, "rrr\n", 4);
}

void	push(t_node **stack_1, t_node **stack_2, t_info *info, char *str)
{
	t_node	*tmp;

	if (!*stack_1)
		return ;
	tmp = (*stack_1);
	(*stack_1) = (*stack_1)->next;
	tmp->next = (*stack_2);
	(*stack_2) = tmp;
	if (str && info && !strcmp(str, "pa\n"))
	{
		info->a_len++;
		info->b_len--;
	}
	else if (info)
	{
		info->b_len++;
		info->a_len--;
	}
	if (str)
		ft_putstr_fd(str, 1);
}
