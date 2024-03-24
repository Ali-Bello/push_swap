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

void	array_sort(int *array, int size)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
}

void	median(int	*array, int size, t_info *info)
{
	if (size % 2 == 0)
	{
		info->med = (array[size / 2 - 1] + array[size / 2]) / 2;
		info->med_idx += size / 2 - 1;
	}
	else
	{
		info->med =  (array[size / 2]);
		info->med_idx += size / 2 ;
	}
}
void    put_array(t_stack *a, int *array)
{
    int    i;

    i = 0;
    while (a)
    {
        array[i++] = a->value;
        a = a->next;
    }
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int find_min(t_stack *b)
{
  int min;

  min = b->value;
  while (b)
  {
    if (b-> value < min)
      min = b->value;
    b = b->next;
  }
  return (min);
}

void	sort_a_less(t_stack **stack, int max)
{
    if ((*stack)->value == max)
        ra(stack);
    else if ((*stack)->next->value == max)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
}

void	sort_b_less(t_stack **stack, int min)
{
    if ((*stack)->value == min)
        rb(stack);
    else if ((*stack)->next->value == min)
        rrb(stack);
    if ((*stack)->value < (*stack)->next->value)
        sb(stack);
}

void	ft_sort_b(t_stack **b, t_stack **a, t_info *info)
{
	int	max;

	while(info->b_len > 3)
	{
		max = find_max(*b);
		while ((*b)->value != max)
			rb(b);
		pa(a, b, info);
	}
	sort_b_less(b, find_min(*b));
  while (info->b_len > 0)
    pa(a, b, info);
}

void	ft_sort(t_stack **a, t_stack **b, t_info *info)
{
	info->array = malloc(sizeof(int) * info->a_len);
	if (!info->array)
		return (free_stack(a), free_stack(b));
	put_array(*a, info->array);
	array_sort(info->array, info->a_len - 1);
	info->med_idx = 0;
	median(info->array, info->a_len, info);
	while (info->a_len > 3)
	{
		while (info->npb < info->med_idx + 1)
		{
			if ((*a)->value <= info->med)
				pb(a, b, info);
			else
				ra(a);
		}
		median(info->array + info->med_idx, info->a_len, info);
	}
	sort_a_less(a, find_max(*a));
	ft_sort_b(b, a, info);
	free(info->array);
}
int	is_inRange(int value, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->a_len)
	{
		if (info->array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	best_move(t_stack **a, t_stack **b , t_info *info)
{
	t_stack	*tmp, *last;

	tmp = *a;
	last = *b;
	while (last)
		last = last->next;
	while ()
	{
		if (is_inRange(tmp->value, info))
		{
			pb(a, b, info);
			tmp = tmp->next;
		}
		else if (is_inRange(last->value, info))
		{
			rra(a);
			pa(a, b, info);
			last = last->prev;
		}
	}
}
/**
 * TODO: -shortest path finder;
 * 		 -where the algo do more moves;
 * 		 error handling;
*/
