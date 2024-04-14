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
	int				len;
    struct s_node	*next;
} t_node;

typedef struct s_info
{
	int	*array;
	int	med;
	int	med_idx;
	int	min;
	int nr;
	int nrr;
} t_info;

void    create_stack(t_node **top, int ac);
void	fill_stack(t_node **top, char **av);
#endif