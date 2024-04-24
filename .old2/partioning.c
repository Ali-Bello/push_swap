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

void	median(int size, t_info *info)
{
	if (size >= info->a_len)
		size = info->a_len - 1;
	if (size)
	{
		info->med_idx += size;
		info->med = (info->array)[info->med_idx];
	}
}

void	best_move(t_node **stack, t_info *info)
{
	int	i, j;
	t_node	*last;
	t_node	*first;

	first = *stack;
	last = get_last(*stack);
	info->nr = 0;
	info->nrr = 0;
	i = 0;
	while (first && first->element >= (info->array)[info->med_idx])
	{
		first = first->next;
		i++;
	}
	j = 1;
	while (last && last->element >= (info->array)[info->med_idx])
	{
		last = last->prev;
		j++;
	}
	if (i > j)
		info->nrr = j;
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
	while (info->a_len > 1)
	{
		add_node(&(info->chunks));
		median(20, info);
		while (info->a_len > 1 && info->b_len < info->med_idx)
		{
			best_move(a, info);
			while (info->nr)
			{
				rotate(a);
				write(1, "ra\n", 3);
				info->nr--;
			}
			while (info->nrr)
			{
				reverse_rotate(a);
				write(1, "rra\n", 4);
				info->nrr--;
			}
			push(a, b, info);
			write(1, "pb\n", 3);
			info->chunks->chunk_size++;
		}
	}
	free(info->array);
}
