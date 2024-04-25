/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:53:30 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/25 19:53:38 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack, char *str)
{
	t_node	*tmp;

	tmp = (*stack)->next;

	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;

	printf("%s", str);
}
