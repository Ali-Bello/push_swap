/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:10 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/23 08:05:02 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int	value;
	int	idx;
	int	len;
	int	npb;
	char	name;
	struct s_stack	*next;
} t_stack;

typedef struct s_info
{
    int	a_len;
    int	b_len;
    int	npb;
	int	med;
	int	med_idx;
} t_info;

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **a);
void	sb(t_stack	**b);
void	sa(t_stack	**a);
void	pa(t_stack **a, t_stack **b, t_info *info);
void	pb(t_stack **a, t_stack **b, t_info *info);


void	ft_sort(t_stack **a, t_stack **b, t_info *info);
void	parse(int ac, char **av, t_stack **head, t_info *info);
void	free_stack(t_stack **head);
#endif
