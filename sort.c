/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:33 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/22 06:21:36 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_sort(int *array, int size)
{
	int	i, j, tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	median(int	*array, int size)
{
	if (size % 2 == 0)
		return ((array[size / 2 - 1] + array[size / 2]) / 2);
	else
		return (array[size / 2]);
}
void	put_array(t_stack *a, int *array)
{
	int	i;

	i = 0;
	while (a)
	{
		array[i++] = a->value;
		a = a->next;
	}
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	med;
	int	*array;

	array = malloc(sizeof(int) * a->len);
	put_array(a, array);
	array_sort(array, a->len - 1);
	med = median(array, a->len);
	while (a->len > 2)
	{
		while (b->npb < med)
		{
			if (a->value <= med)
				pb(&a, &b);
			else
				ra(&a);
		}
		med = median(array + med, a->len);
	}
	sort_2(a);
	ft_sort_b(b, a);
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

void	ft_sort_b(t_stack *b, t_stack *a)
{
	int	max;

	while(b->len > 2)
	{
		max = find_max(b);
		while (b->value != max)
			rb(&b);
		pa(&a, &b);
	}
	sort_2(b);
	pa(&a, &b);
	pa(&a, &b);
}

void	sort_2(t_stack *stack)
{
	void	(*function)(t_stack **);

	if (stack->name == 'a')
		function = &sa;
	else
		function = &sb;
	if (stack->value > stack->next->value)
		function(&stack);
}
/**
 * TODO: -implement the sort B function;
 * 		 -implement the sort 3 elements function;
 * 		 -implement the shortest path finder function;
 *		 [THE PARSING PART];
*/
