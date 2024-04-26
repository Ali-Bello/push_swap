#include "push_swap.h"

void	free_args(char **args)
{
	int i;

	i = 0;
	while (args && args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	stack = 0;
}
// int main(int ac, char **av)
// {
// 	t_node	*a;
// 	t_node	*b;
// 	t_info	info;
// 	char	**args;

// 	args = parse(av + 1, &(info.a_len));
// 	if (ac < 2 || is_sorted(args))
// 		return (free_args(args), 0);
// 	a = 0;
// 	b = 0;
// 	info.b_len = 0;
// 	create_stack(&a, &info);
// 	fill_stack(&a, args);
// 	push_to_b(&a, &b, &info);
// 	sort(&a, &b, &info);
// 	free_args(args);
// 	free_stack(a);
// }
