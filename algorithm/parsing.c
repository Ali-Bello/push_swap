/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:54:36 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 06:46:41 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isNum(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9')
			&& !(str[i] >= 9 && str[i] <= 13) &&(str[i] != ' '))
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
		if (!isNum(av[i]))
		{
			free(buffer);
			ft_putstr_fd("Error\n", 2);
			exit (-1);
		}
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
	while (av && av[i])
	{
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

int	is_notNum(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av && av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9')
				&& (av[i][j] != ' ') && !(av[i][j] >= 9 && av[i][j] <= 13))
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


	args = get_args(av, a_len);
	if (is_duplicate(args) || is_notNum(args))
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
