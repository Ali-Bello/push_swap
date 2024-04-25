/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:56:48 by marvin            #+#    #+#             */
/*   Updated: 2024/04/24 21:52:26 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				element;
	int				a_r;
	int				a_rr;
	int				b_r;
	int				b_rr;
	int				rr;
	int				rrr;
	int				is_max;
	struct s_node	*next;
} t_node;

typedef struct s_info
{
	int	a_len;
	int	b_len;
	int	a_max;
	int	a_min;
	int	b_max;
	int	b_min;
	int	nr;
	int	nrr;
	int	a_r;
	int	a_rr;
	int	b_r;
	int	b_rr;
	int	rr;
	int	rrr;
} t_info;

void	create_stack(t_node **top, t_info *info, int ac);
void	fill_stack(t_node **top, char **av);
void	partition(t_node **a, t_node **b, t_info *info);
void	sort(t_node **a, t_node **b, t_info *info);
void	push(t_node	**a, t_node	**b, t_info *info);
void	push_b(t_node	**a, t_node	**b, t_info *info);
void	swap(t_node **stack);
void	rotate(t_node **top);
void	rr(t_node **a, t_node **b);
void    reverse_rotate(t_node **top);
void	rrr(t_node **a, t_node **b);
t_node *get_last(t_node *stack);
void	push_everything(t_node **a, t_node **b, t_info *info);
void	set_max_min(t_node **b, t_info *info);
void	bring_max(t_node **stack, t_info *info);
void	find_insert_pos(int value, t_node **b, t_info *info);
void	apply_moves(t_node **a, t_node **b, t_info *info);
void	sort_three(t_node **a);
void	bring_max(t_node **stack, t_info *info);
#endif
