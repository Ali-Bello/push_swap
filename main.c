#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_stack
{
    int    value;
    struct s_stack   *next;
} t_stack;

typedef struct s_info
{
    int    len;
    int    min;
    int    max;
    int    npb;
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

int    median(int    *array, int size)
{
    if (size % 2 == 0)
        return ((array[size / 2 - 1] + array[size / 2]) / 2);
    else
        return (array[size / 2]);
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
    write(1, "ra", 2);
}

void    pb(t_stack **a, t_stack **b, t_info *info)
{
  t_stack *tmp;

  tmp = *a;
  *a = (*a)->next;
  tmp->next = *b;
  *b = tmp;
  info->len--;
  info->npb++;
  write(1, "pb", 2);
}

void    ft_sort(t_stack *a, t_stack *b , t_info *info)
{
    int    med;
    int    *array;

    array = malloc(sizeof(int) * info->len);
    put_array(a, array);
    array_sort(array, info->len - 1);
    med = median(array, info->len);
    while (info->len > 3)
    {
        while (info->npb <= med)
        {
            if (a->value <= med)
                pb(&a, &b, info);
            else
                ra(&a);
        }
        med = median(array + med, info->len);
    }
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
  info->len++;
}

void create_stack(t_stack **head, t_info *info)
{
  t_stack *x = malloc(sizeof(t_stack));
  t_stack *y = malloc(sizeof(t_stack));
  t_stack *z = malloc(sizeof(t_stack));
  t_stack *a = malloc(sizeof(t_stack));
  t_stack *b = malloc(sizeof(t_stack));
  t_stack *c = malloc(sizeof(t_stack));
  *head = 0;
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
  info.len = 0;
  info.npb = 0;
  b = 0;
  create_stack(&a, &info);
  ft_sort(a, b, &info);
  return 0;
}
