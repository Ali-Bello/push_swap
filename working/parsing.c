/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:54:36 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/25 22:49:22 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse(char **av)
{
	char	*buffer;
	char	*tmp;
	int		i;

	buffer = NULL;
	i = 1;
	while (av[i])
	{
		tmp = ft_strjoin(ft_strdup(av[i++]), " ");
		buffer = ft_strjoin(buffer, tmp);
	}
	return (ft_split(buffer, ' '));
}
