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
	printf("array + med_idx = [%d]\n", *array);
	printf("size = [%d]\n", size);
	if (size)
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
}
void    put_array(t_stack *a, t_info *info)
{
    int    i;

    i = 0;
    while (a && info->a_len)
    {
        (info->array)[i++] = a->value;
        a = a->next;
    }
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
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

	if (!b)
		return (0);
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
	while (i <= n)
	{
		if ((info->array)[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	best_move(t_stack **stack, t_info *info, int n)
{
	t_stack	*tmp, *last;
	int	x;

	tmp = *stack;
	last = *stack;
	info->nr = 0;
	info->nrr = 0;
	while (last->next)
		last = last->next;
	printf("first -> [%d]\nlast -> [%d]\n", tmp->value, last->value);
	
	while (1)
	{
		if (is_inRange(tmp->value, n, info))
			break;
		if (is_inRange(last->value, n, info))
		{
			info->nrr++;
			break;
		}
		info->nr++;
		tmp = tmp->next;
		last = last->prev;
	}
}

void	ft_sort_b(t_stack **b, t_stack **a, t_info *info)
{
	while(info->b_len > 3)
	{
		*(info->array) = find_max(*b);
		best_move(b, info, 1);
		if (info->nr > info->nrr)
		{
			while (info->nr)
			{
				rb(b);
				info->nr--;
			}
		}
		else
		{
			while (info->nrr)
			{
				rrb(b);
				info->nrr--;
			}
		}
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
	put_array(*a, info);
	array_sort(info->array, info->a_len);
	info->med_idx = 0;
	median(info->array, info->a_len, info);
	while (info->a_len > 3)
	{
		while (info->npb < info->med_idx + 1)
		{
			best_move(a, info, info->med_idx);
			if (info->nr >= info->nrr)
			{
				while (info->nr)
				{
					ra(a);
					info->nr--;
				}
			}
			else
			{
				while (info->nrr)
				{
					rra(a);
					info->nrr--;
				}
			}
			pb(a, b, info);
		}		
		median(info->array + info->med_idx , info->a_len, info);
	}
	sort_a_less(a, find_max(*a));
	ft_sort_b(b, a, info);
	free(info->array);
}

/**
 * TODO: -shortest path finder;
 * 		 -where the algo do more moves;
 * 		 error handling;
*/
