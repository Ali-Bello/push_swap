#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *a, *b ,**tmp;
	t_info	info;

	b = 0;
	parse(ac - 1, av + 1, &a, &info);
	tmp = &a;
	printf("--- stack created ---\n");
	while (*tmp)
	{
		printf("\t[%d]\n", (*tmp)->value);
		*tmp = (*tmp)->next;
	}
	printf("-----------------------");
  ft_sort(&a, &b, &info);
  	tmp = &a;
	printf("--- stack sorted ---\n");
	while (*tmp)
	{
		printf("\t[%d]\n", (*tmp)->value);
		*tmp = (*tmp)->next;
	}
	printf("-----------------------");
	free_stack(&a);
}
/**
 * TODO:
 *       implement the finding function;
 *       parsing part;
*/
