/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:10:17 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 23:38:55 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithm/push_swap.h"
#include "get_next_line.h"

int	is_stack_sorted(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	exec_moves(char *move, t_node **a, t_node **b)
{
	if (!ft_strncmp(move, "ra\n", 3))
		rotate(a, NULL);
	else if (!ft_strncmp(move, "rra\n", 4))
		reverse_rotate(a, NULL);
	else if (!ft_strncmp(move, "rb\n", 4))
		reverse_rotate(b, NULL);
	else if (!ft_strncmp(move, "rrb\n", 4))
		reverse_rotate(b, NULL);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr(a, b, NULL);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(a, b, NULL);
	else if (!ft_strncmp(move, "sa\n", 3))
		swap(a, NULL);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap(b, NULL);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(move, "pa\n", 3))
		push(b, a, NULL, NULL);
	else if (!ft_strncmp(move, "pb\n", 3))
		push(a, b, NULL, NULL);
	else
		return (0);
	return (1);
}

void	parse_operations(t_node **a, t_node **b)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		if (!exec_moves(move, a, b))
		{
			free_stack(*a);
			free_stack(*b);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		free(move);
	}
}

void	checker(t_node **a, t_node **b)
{
	parse_operations(a, b);
	if (!*b && is_stack_sorted(*a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(*a);
	free_stack(*b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_info	info;
	char	**args;

	args = parse(av + 1, &(info.a_len));
	if (ac < 2)
		return (free_args(args), 0);
	a = 0;
	b = 0;
	info.b_len = 0;
	create_stack(&a, &info);
	fill_stack(&a, args);
	free_args(args);
	checker(&a, &b);
}
