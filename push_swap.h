/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:10 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/21 00:12:57 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	value;
	int	idx;
	struct s_stack	*next;
} t_stack;

typedef struct s_info
{
	int	len;
	int	min;
	int	max;
	int	npb;
} t_info;

#endif
