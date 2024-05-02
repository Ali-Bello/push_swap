/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:54:36 by aderraj           #+#    #+#             */
/*   Updated: 2024/05/01 22:14:49 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *str)
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
		if (is_empty(av[i]))
		{
			free(buffer);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		tmp = ft_strjoin(ft_strdup(av[i++]), " ");
		if (!tmp)
			return (free(tmp), free(buffer), NULL);
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(tmp), NULL);
		free(tmp);
	}
	return (ft_split(buffer, ' ', a_len));
}

int	is_sorted(char **av)
{
	int	i;

	i = 0;
	while (*av && av[i + 1])
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
	if (*av && !av[1])
		ft_safe_atoi(av[i], av);
	while (av && av[i])
	{
		if (!is_valid(av[i]))
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

	if (!*av)
		return (NULL);
	args = get_args(av, a_len);
	if (!*args || is_duplicate(args))
	{
		free_args(args);
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	return (args);
}
