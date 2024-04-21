/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:53:56 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/22 00:32:06 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_there_bigger(int value, t_node **b, t_info *info)
{
	t_node	*tmp;
	int	i = 1;

	tmp = (*b);
	while (i < info->chunks->chunk_size)
	{
		if (tmp->element > value)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	reset_rotations(t_node **a, t_node **b, t_info *info)
{
	t_node	*last;

	last = get_last(*a);
	while (!is_there_bigger(last->element, b, info) && info->nr)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		last = get_last(*a);
		info->nr--;
	}
}

void	insert_a(t_node **a, t_node **b, t_info *info)
{
	while ((*b)->element > (*a)->element)
	{
		rotate(a);
		write(1, "ra\n", 3);
		info->nr++;
	}
	push_b(b, a, info);
	write(1, "pa\n", 3);
	if (info->b_len > 2 && (*b)->element < (*b)->next->element)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	sort_chunk(t_node **a, t_node **b, t_info *info)
{
	t_node	*last;

	while (info->nr)
	{
		last = get_last(*a);
		while(last->element > (*a)->element)
		{
			push(a, b, info);
			write(1, "pb\n", 3);
			info->chunks->chunk_size++;
		}
		if ((*b) && (*b)->element < (*b)->next->element)
		{
			swap(b);
			write(1, "sb\n", 3);
		}
		reverse_rotate(a);
		write(1, "rra\n", 4);
		info->nr--;
	}
}

void	sort(t_node **a, t_node **b, t_info *info)
{
	int	i;
	int x, y;

	t_chunk *tmp2 = info->chunks;
	while (info->b_len)
	{
		i = 0;
		info->nr = 0;
		while (info->b_len && info->chunks->chunk_size > 0)
		{
			insert_a(a, b, info);
			info->chunks->chunk_size--;
		}
		// printf("info->nr = [%d]\n", info->nr);
		sort_chunk(a, b, info);
		// t_node	*tmp;
		// tmp = (*a);
		// while (tmp)
		// {
		// 	printf("a = [%d]\n", tmp->element);
		// 	tmp = tmp->next;
		// }
		// printf("------\n");
		// tmp = (*b);
		// while (tmp)
		// {
		// 	printf("b = [%d]\n", tmp->element);
		// 	tmp = tmp->next;
		// }
		// printf("------\n");
		if (info->chunks->chunk_size == 0)
			info->chunks = info->chunks->next;
	}
}

