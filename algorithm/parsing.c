/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:54:36 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 23:34:30 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char	**get_args(char **av, int *a_len)
{
	char	*buffer;
	char	*tmp;
	int		i;

	buffer = NULL;
	i = 0;
	while (av[i])
	{
		tmp = ft_strjoin(ft_strdup(av[i++]), " ");
		buffer = ft_strjoin(buffer, tmp);
		free(tmp);
	}
	return (ft_split(buffer, ' ', a_len));
}

int	is_sorted(char **av)
{
	int	i;

	i = 0;
	while (av[i + 1])
	{
		if (ft_safe_atoi(av[i], av) > ft_safe_atoi(av[i + 1], av))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (av && !av[1])
		ft_safe_atoi(av[i], av);
	while (av && av[i])
	{
		if (!is_num(av[i]))
			return (1);
		j = i + 1;
		while (av[j])
		{
			if (ft_safe_atoi(av[i], av) == ft_safe_atoi(av[j], av))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**parse(char **av, int *a_len)
{
	char	**args;
	int		i;

	if (!*av)
		return (NULL);
	args = get_args(av, a_len);
	if (!args || !*args || is_duplicate(args))
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	return (args);
}
