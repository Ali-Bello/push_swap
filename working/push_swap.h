/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:52:42 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/25 22:32:02 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_info
{
	int	a_len;
	int	b_len;
	int	max;
	int	min;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
} t_info;

typedef struct s_node
{
	int				value;
	t_info			info;
	struct s_node	*next;
} t_node;

void	create_stack(t_node **top, t_info *info);
void	fill_stack(t_node **top, char **av);

void	push(t_node	**stack_1, t_node **stack_2, t_info *info, char *str);
void	swap(t_node **stack, char *str);
void	rotate(t_node **stack, char *str);
void	reverse_rotate(t_node **stack, char *str);
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);

void	init_zero(t_info *info);
void	set_min_max(t_node **stack, t_info *info);
void	bring_to_top(t_node **stack, t_info *info);
void	apply_moves(t_node **a, t_node **b, t_info *info);
void	reduce_price(t_node **a);

void	push_to_b(t_node **a, t_node **b, t_info *info);
void	sort(t_node **a, t_node **b, t_info *info);
char	**parse(char **av);
#endif
