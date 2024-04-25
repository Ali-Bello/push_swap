#include "push_swap.h"

int main(int ac, char **av)
{
	t_node	*a, *b;
	t_info	info;
	a = 0;
	b = 0;
	info.a_len = ac - 1;
	info.b_len = 0;
	create_stack(&a, &info);
	fill_stack(&a, av);
	push_to_b(&a, &b, &info);
	sort(&a, &b, &info);
}
