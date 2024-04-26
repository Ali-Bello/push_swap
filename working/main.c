#include "push_swap.h"

void	free_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_info	info;
	char	**args;

	args = parse(av + 1, &(info.a_len));
	if (ac < 2 || is_sorted(args))
		return (free_args(args), -1);
	a = 0;
	b = 0;
	info.b_len = 0;
	create_stack(&a, &info);
	fill_stack(&a, args);
		t_node *tmp = a;
	while (tmp)
	{
		printf("a-> [%d]\n", tmp->value);
		tmp = tmp->next;
	}
	push_to_b(&a, &b, &info);
	sort(&a, &b, &info);
}
