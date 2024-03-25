/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:06 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/23 07:56:46 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack	**a)
{
    int tmp;

    tmp = (*a)->value;
    (*a)->value = (*a)->next->value;
    (*a)->next->value = tmp;
    write(1, "sa\n", 3);
}

void	sb(t_stack	**b)
{
    int tmp;

    tmp = (*b)->value;
    (*b)->value = (*b)->next->value;
    (*b)->next->value = tmp;
    write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
