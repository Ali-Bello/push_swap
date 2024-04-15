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

void	put_array(t_node *a, int *array)
{
	int	i;

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
	size = info->a_len * (info->a_len > 2) + info->b_len * (info->a_len == 2);
	i = 0;
	while (stack && stack->element >= value)
	{
		stack = stack->next;
		i++;
	}
	if (i > size / 2)
		info->nrr = size - i;
	else
		info->nr = i;
}

void	add_node(t_chunk **chunks)
{
	t_chunk	*tmp;

	tmp = malloc(sizeof(t_chunk));
	if (!tmp)
		return;
	tmp->chunk_size = 0;
	tmp->next = *chunks;
	*chunks = tmp;
}

void	partition(t_node **a, t_node **b, t_info *info)
{
	info->med_idx = 0;
	info->array = malloc(info->a_len * sizeof(int));
	info->chunks = 0;
	put_array(*a, info->array);
	array_sort(info->array, info->a_len);
	while (info->a_len > 2)
	{
		add_node(&(info->chunks));
		median(info->array + info->b_len, info->a_len, info);
		while (info->b_len < info->med_idx + 1)
		{
			best_move(*a, info, info->med);
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
			push(a, b, info);
			write(1, "pb\n", 3);
			info->chunks->chunk_size++;
		}
	}
	if ((*a)->element > (*a)->next->element)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	free(info->array);
}
