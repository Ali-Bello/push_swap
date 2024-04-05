/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 06:56:44 by aderraj           #+#    #+#             */
/*   Updated: 2024/03/24 06:07:50 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		++i;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

void	add_node(t_stack **a, t_info *info)
{
    t_stack *last;

    last = *a;
	while (last && last->next)
        last = last->next;
	if (!last)
    {
        *a = malloc(sizeof(t_stack));
		if (!*a)
			return ;
        (*a)->prev = NULL;
		(*a)->next = NULL;
    }
    else
    {
        last->next = malloc(sizeof(t_stack));
        last->next->prev = last;
		last->next->next = 0;
    }
    info->a_len++;
}

void	create_stack(t_stack **head, int len, t_info *info)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (i++ < len)
		add_node(head, info);
}
void	parse(int ac, char **av, t_stack **head, t_info *info)
{
	t_stack	*tmp;

	create_stack(head, ac , info);
	tmp = *head;
	while (ac)
	{
		tmp->value = ft_atoi(av[ac--]);
		tmp = tmp->next;
	}
}

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = 0;
}

