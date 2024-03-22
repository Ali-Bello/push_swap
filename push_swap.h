/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:33:10 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/22 06:18:52 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	value;
	int	idx;
	int	len;
	int	npb;
	char	name;
	struct s_stack	*next;
} t_stack;


void	sb(t_stack	**b);
void	sa(t_stack	**a);
#endif
