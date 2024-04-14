/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partioning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:29:44 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 18:29:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    put_array(t_node *a, int *array)
{
    int    i;

    i = 0;
    while (a)
    {
        array[i++] = a->element;
        a = a->next;
    }
}

// insertion sort
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
			info->med_idx += size / 2;
		}
	}
}

void	best_move(t_node *stack, t_info *info, int value)
{
	int	i;
	int	size;

	info->nr = 0;
	info->nrr = 0;
	size = stack->len;
	i = 0;
	while (stack && stack->element != value)
	{
		stack = stack->next;
		i++;
	}
	if (i > size / 2)
		info->nrr = i;
	else
		info->nr = i;
}

void    partition(t_node **a, t_node **b, t_info *info)
{
    info->med_idx = 0;
    info->array = malloc((*a)->len * sizeof(int));

    put_array(*a, info->array);
    median(info, (*a)->len, info);
    while ((*a)->len > 2)
    {
        while ((*b)->len < info->med_idx + 1)
		{
			best_move(a, info, info->med);
			while (info->nr--)
			{
				rotate(a);
				write(1, "ra\n", 3);
			}
			while (info->nrr--)
			{
				reverse_rotate(a);
				write(1, "rra\n", 4);
			}
			push(a, b);
			write(1, "pb\n", 3);
		}
		median(info->array + info->med_idx, (*a)->len, info);
    }
	free(info->array);
}