/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:04:31 by marvin            #+#    #+#             */
/*   Updated: 2024/03/26 15:04:31 by marvin           ###   ########.fr       */
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