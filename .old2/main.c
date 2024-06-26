/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:24:05 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 18:24:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_node	*a, *b;
	t_info	info;
	a = 0;
	b = 0;
	info.a_len = 0;
	info.b_len = 0;
	create_stack(&a, &info, ac - 1);
	fill_stack(&a, av);
	partition(&a, &b, &info);
	sort(&a, &b, &info);
}
