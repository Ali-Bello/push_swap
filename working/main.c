#include "push_swap.h"

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_info	info;
	char	**args;

	args = parse(av);
	for (int i = 0; args[i]; i++)
		printf("[%s]\n", args[i]);

	// a = 0;
	// b = 0;
	// info.a_len = ac - 1;
	// info.b_len = 0;
	// create_stack(&a, &info);
	// fill_stack(&a, av);
	// push_to_b(&a, &b, &info);
	// sort(&a, &b, &info);
}
