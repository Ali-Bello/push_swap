#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *a, *b ,**tmp;
	t_info	info;

	b = 0;
	info.a_len = 0;
	info.b_len = 0;
	info.npb = 0;
	info.med_idx = 0;
	parse(ac - 1, av + 1, &a, &info);
	tmp = &a;
	// printf("--- stack created ---\n");
	// while (*tmp)
	// {
	// 	printf("\t[%d]\n", (*tmp)->value);
	// 	*tmp = (*tmp)->next;
	// }
	// printf("-----------------------");
	// printf("a = [%p]\n", a);

	ft_sort(&a, &b, &info);
	// tmp = &a;
	// printf("--- stack sorted ---\n");
	// while (*tmp)
	// {
	// 	printf("\t[%d]\n", (*tmp)->value);
	// 	*tmp = (*tmp)->next;
	// }
	// printf("-----------------------");
	free_stack(&a);
}
/**
 * TODO:
 *       implement the finding function;
 *       parsing part;
*/
