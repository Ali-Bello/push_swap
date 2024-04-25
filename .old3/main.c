#include "push_swap.h"

int main(int ac, char **av)
{
	t_node	*a, *b;
	t_info	info;
	a = 0;
	b = 0;
	info.a_len = 0;
	info.b_len = 0;
	create_stack(&a, &info, ac - 1);
	fill_stack(&a, av);
	push_everything(&a, &b, &info);
	printf("------\n");
	sort_three(&a);
	info.nr = 0;
	info.nrr = 0;
	bring_max(&b, &info);
	while (info.nr > 0)
	{
		rotate(&b);
		write(1, "rb\n", 3);
		info.nr--;
	}
	while (info.nrr > 0)
	{
		reverse_rotate(&b);
		write(1, "rrb\n", 4);
		info.nrr--;
	}
	sort(&a, &b, &info);
}
