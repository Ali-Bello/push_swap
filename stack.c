/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:15:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 17:15:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_node **top, char **av)
{
	t_node	*tmp;
	int	i;

	i = 1;
	tmp = *top;
	while (i < (*top)->len + 1)
	{
		tmp->element = ft_atoi(av[i]);
		tmp = tmp->next;
		i++;
	}
}

void    create_stack(t_node **top, int ac)
{
	t_node	*tmp;
	int     i;

    i = 0;
	while (i < ac)
	{
		tmp = malloc(sizeof(t_node));
		tmp->next = *top;
		if (*(top))
			tmp->len = (*top)->len + 1;
		else
			tmp->len = 1;
		(*top) = tmp;
		i++;
	}
}