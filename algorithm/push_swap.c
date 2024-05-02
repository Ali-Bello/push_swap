/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:23:54 by aderraj           #+#    #+#             */
/*   Updated: 2024/05/01 22:16:30 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_info	info;
	char	**args;

	args = parse(av + 1, &(info.a_len));
	if (ac < 2 || is_sorted(args))
		return (free_args(args), 0);
	a = 0;
	b = 0;
	info.b_len = 0;
	create_stack(&a, &info);
	if (!a)
		return (free(args), -1);
	fill_stack(&a, args);
	free_args(args);
	push_to_b(&a, &b, &info);
	sort(&a, &b, &info);
	free_stack(a);
}
