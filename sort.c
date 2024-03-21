/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:33 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/21 00:33:53 by aderraj          ###   ########.fr       */
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

void	ft_sort(t_stack *a, t_stack *b , t_info *info)
{
	int	med;
	int	*array;

	array = malloc(sizeof(int) * info->len);
	put_array(a, array);
	array_sort(array, info->len - 1);
	med = median(array, info->len);
	while (info->len > 3)
	{
		while (info->npb <= med)
		{
			if (a->value <= med)
				pb(&a, &b, info);
			else
				ra(&a);
		}
		med = median(array + med, info->len);
	}
}

/**
 * TODO: -implement the shortest path finder function;
 * 		 -implement the sort B function;
 *  	 -implement the sort 3 elements function;
 *		 [THE PARSING PART];
*/
