/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:33 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/24 08:02:14 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_less(t_stack **stack, int max)
{
	if (*stack)
	{
    	if ((*stack)->value == max)
        	ra(stack);
    	else if ((*stack)->next->value == max)
        	rra(stack);
    	if ((*stack)->value > (*stack)->next->value)
        	sa(stack);
	}
}

void	sort_b_less(t_stack **stack, int min)
{
	if (*stack)
	{
    	if ((*stack)->value == min)
        	rb(stack);
    	else if ((*stack)->next->value == min)
        	rrb(stack);
    	if ((*stack)->value < (*stack)->next->value)
        sb(stack);
	}
}

int	is_inRange(int value, int n, t_info *info)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (info->array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	best_move(t_stack **stack, t_info *info, int n)
{
	t_stack	*tmp, *last;


	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	while (!is_inRange(tmp->value, n, info))
	{
		info->nr++;
		tmp = tmp->next;
	}
	while (info->nr && !is_inRange(last->value, n, info))
	{
		info->nrr++;
		last = last->prev;
	}
}

void	ft_sort_b(t_stack **b, t_stack **a, t_info *info)
{
	free(info->array);
	while(info->b_len > 2)
	{
		info->nr = 0;
		info->nrr = 1;
		*(info->array) = find_max(*b);
		best_move(b, info, 1);
		if (info->nr <= info->nrr)
		{
			while (info->nr--)
				rb(b);
		}
		else
		{
			while (info->nrr--)
				rrb(b);
		}
		pa(a, b, info);
	}
	if ((*b)->value > (*b)->next->value)
		sb(b);
  	while (info->b_len > 0)
   		pa(a, b, info);
}

int	partion(t_stack **a, t_info *info)
{
	info->nr = 0;
	info->nrr = 1;
	best_move(a, info, info->med_idx + 1);
	if (info->nr <= info->nrr)
	{
		while (info->nr--)
			ra(a);
	}
	else
	{
		while (info->nrr--)
			rra(a);
	}
	return (1);
}

void	ft_sort(t_stack **a, t_stack **b, t_info *info)
{
	info->array = malloc(sizeof(int) * info->a_len);
	if (!info->array)
		return (free_stack(a), free_stack(b));
	put_array(*a, info);
	array_sort(info->array, info->a_len);
	info->med_idx = 0;
	median(info->array, info->a_len, info);
	while (info->a_len > 2)
	{
		while (info->b_len < info->med_idx + 1)
		{
			partion(a, info);
			pb(a, b, info);
		}
		median(info->array + info->med_idx, info->a_len, info);
	}
	if ((*a)->value > (*a)->next->value)
		sa(a);
	ft_sort_b(b, a, info);
}

/**
 * TODO: -where does the algo do more moves ?;
 * 		 -error handling;
*/
