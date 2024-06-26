#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b, *tmp;
	t_info	info;

	a = 0;
	b = 0;
	info.a_len = 0;
	info.b_len = 0;
	info.npb = 0;
	info.med_idx = 0;
	parse(ac - 1, av, &a, &info);
	ft_sort(&a, &b, &info);
	free_stack(&a);
}
