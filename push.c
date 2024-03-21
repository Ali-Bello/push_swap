/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:13 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/21 00:13:19 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_info *info)
{
  t_stack *tmp;

  tmp = *b;
  *b = (*b)->next;
  tmp->next = *a;
  *a = tmp;
  info->len--;
  write(1, "pa", 2);
}

void	pb(t_stack **a, t_stack **b, t_info *info)
{
  t_stack *tmp;

  tmp = *a;
  *a = (*a)->next;
  tmp->next = *b;
  *b = tmp;
  info->len--;
  info->npb++;
  write(1, "pb", 2);
}
