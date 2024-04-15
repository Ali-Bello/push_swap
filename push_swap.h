/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:56:48 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 17:56:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
    int				element;
    struct s_node	*next;
} t_node;

typedef struct s_chunk
{
	int chunk_size;
	struct s_chunk *next;
} t_chunk;

typedef struct s_info
{
	int	a_len;
	int	b_len;
	int	*array;
	int	med;
	int	med_idx;
	int nr;
	int nrr;
	t_chunk *chunks;
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
#endif
