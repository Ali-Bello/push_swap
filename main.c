#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_stack
{
	int	value;
	int	idx;
	struct s_stack	*next;
} t_stack;

typedef struct s_info
{
    int	a_len;
    int	b_len;
    int	npb;
	int	med;
	int	med_idx;
} t_info;

void    array_sort(int *array, int size)
{
    int    i, j, tmp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j <= size)
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void	median(int	*array, int size, t_info *info)
{
	if (size % 2 == 0)
	{
		info->med = (array[size / 2 - 1] + array[size / 2]) / 2;
		info->med_idx += size / 2 - 1;
	}
	else
	{
		info->med =  (array[size / 2]);
		info->med_idx += size / 2 ;
	}
}
void    put_array(t_stack *a, int *array)
{
    int    i;

    i = 0;
    while (a)
    {
        array[i++] = a->value;
        a = a->next;
    }
}
void    ra(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = (*a);
    (*a) = (*a)->next;
    tmp->next->next = 0;
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    t_stack *tmp;

    tmp = *b;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = (*b);
    (*b) = (*b)->next;
    tmp->next->next = 0;
    write(1, "rb\n", 3);
}

void	pa(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	info->a_len++;
	info->b_len--;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_info *info)
{
  t_stack *tmp;

  tmp = *a;
  *a = (*a)->next;
  tmp->next = *b;
  *b = tmp;
	info->a_len--;
	info->b_len++;
	info->npb++;
  write(1, "pb\n", 3);
}
void	sa(t_stack	**a)
{
    int tmp;

    tmp = (*a)->value;
    (*a)->value = (*a)->next->value;
    (*a)->next->value = tmp;
    write(1, "sa\n", 3);
}

void	sb(t_stack	**b)
{
    int tmp;

    tmp = (*b)->value;
    (*b)->value = (*b)->next->value;
    (*b)->next->value = tmp;
    write(1, "sb\n", 3);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void    rra(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next)
    {
      if (!(tmp->next->next))
        break;
      tmp = tmp->next;
    }
    tmp->next->next = (*a);
    (*a) = tmp->next;
    tmp->next = 0;
    write(1, "rra\n", 4);
}
void    rrb(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next)
    {
      if (!(tmp->next->next))
        break;
      tmp = tmp->next;
    }
    tmp->next->next = (*a);
    (*a) = tmp->next;
    tmp->next = 0;
    write(1, "rrb\n", 4);
}

int find_min(t_stack *b)
{
  int min;

  min = b->value;
  while (b)
  {
    if (b-> value < min)
      min = b->value;
    b = b->next;
  }
  return (min);
}

void	sort_a_less(t_stack **stack, int max)
{
  printf("max = %d\n", max);
    if ((*stack)->value == max)
        ra(stack);
    else if ((*stack)->next->value == max)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
}
void	sort_b_less(t_stack *stack, int min)
{
    if (stack->value == min)
        rb(&stack);
    else if (stack->next->value == min)
        rrb(&stack);
    if (stack->value < stack->next->value)
        sb(&stack);
}
void	ft_sort_b(t_stack *b, t_stack *a, t_info *info)
{
	int	max;
  t_stack *tmp, *tmp2;

	while(info->b_len > 3)
	{
		max = find_max(b);
		while (b->value != max)
			rb(&b);
		pa(&a, &b, info);
	}
  tmp = a;
  printf("-----stack a----\n");
  while (tmp)
  {
    printf("[%d]\n", tmp->value);
    tmp = tmp->next;
  }
  printf("----------------\n");

	sort_b_less(b, find_min(b));
  tmp2 = b;
  printf("-----stack b----\n");
  while (tmp2)
  {
    printf("[%d]\n", tmp2->value);
    tmp2 = tmp2->next;
  }
  printf("----------------\n");
  pa(&a, &b, info);
}

void	ft_sort(t_stack *a, t_stack *b, t_info *info)
{
	int	*array;
  t_stack *tmp;

	array = malloc(sizeof(int) * info->a_len);
	put_array(a, array);
	array_sort(array, info->a_len - 1);
	info->med_idx = 0;
	median(array, info->a_len, info);
	while (info->a_len > 3)
	{
		while (info->npb <= info->med)
		{
			if (a->value <= info->med)
				pb(&a, &b, info);
			else
				ra(&a);
		}
		median(array + info->med_idx, info->a_len, info);
	}
	sort_a_less(&a, find_max(a));
	ft_sort_b(b, a, info);
}

void  add_node(t_stack **a, t_stack *new, t_info *info)
{
  t_stack *last;

  last = *a;
  while (last && last->next)
    last = last->next;
  if (!last)
    *a = new;
  else
    last->next = new;
  new->next = 0;
  info->a_len++;
}

void create_stack(t_stack **head, t_info *info)
{
  t_stack *x = malloc(sizeof(t_stack));
  t_stack *y = malloc(sizeof(t_stack));
  t_stack *z = malloc(sizeof(t_stack));
  t_stack *a = malloc(sizeof(t_stack));
  t_stack *b = malloc(sizeof(t_stack));
  t_stack *c = malloc(sizeof(t_stack));

  x->value = 5;
  y->value = 4;
  z->value = 3;
  a->value = 2;
  b->value = 1;
  c->value = 0;
  add_node(head, x, info);
  add_node(head, y, info);
  add_node(head, z, info);
  add_node(head, a, info);
  add_node(head, b, info);
  add_node(head, c, info);
}
int main() {

  t_stack *a, *b;
  t_info info;
    a = 0;
    b = 0;

    info.a_len = 0;
    info.b_len = 0;
    info.npb = 0;
  create_stack(&a, &info);
  ft_sort(a, b, &info);
  return 0;
}

/**
 * TODO: implement sort_b_less correctly;
 *       implement the finding function;
 *       parsing part;
*/
