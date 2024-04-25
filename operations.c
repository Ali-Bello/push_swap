/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:58:49 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/25 02:08:16 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack, char *str)
{
	t_node	*tmp;
	t_node	*new_top;

	tmp  = *stack;
	while (tmp->next)
		tmp = tmp->next;

	new_top = (*stack)->next;

	(*stack)->next = 0;
	tmp->next = (*stack);

	(*stack) = new_top;

	if (str)
		printf("%s", str);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_node **stack, char *str)
{
	t_node	*tmp;
	t_node	*prev;

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
		printf("%s", str);
}
void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	write(1, "rrr\n", 4);
}

void	push(t_node	**stack_1, t_node **stack_2, t_info *info, char *str)
{
	t_node	*tmp;

	tmp = (*stack_1);

	(*stack_1) = (*stack_1)->next;

	tmp->next = (*stack_2);
	(*stack_2) = tmp;

	if (!strcmp(str, "pa\n"))
	{
		info->a_len++;
		info->b_len--;
	}
	else
	{
		info->b_len++;
		info->a_len--;
	}
	printf("%s", str);
}

void	swap(t_node **stack, char *str)
{
	t_node	*tmp;

	tmp = (*stack)->next;

	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;

	printf("%s", str);
}
