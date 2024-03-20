#include <stdio.h>
#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int    value;
    struct s_stack   *next;
} t_stack;

void  add_node(t_stack **a, t_stack *new)
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
}

void create_stack(t_stack **head)
{
  t_stack *x = malloc(sizeof(t_stack));
  t_stack *y = malloc(sizeof(t_stack));
  t_stack *z = malloc(sizeof(t_stack));

  *head = 0;
  x->value = 2;
  y->value = 1;
  z->value = 3;

  add_node(head, x);
  add_node(head, y);
  add_node(head, z);
}

void    rra(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next)
    {
      if (tmp->next->next == NULL)
        break;
      tmp = tmp->next;
    }
    tmp->next->next = (*a);
    (*a) = tmp->next;
    tmp->next = 0;
}

int main() {

  t_stack *a,*tmp;

  create_stack(&a);
  tmp = a;
  while (tmp)
  {
    printf("[%d]\n", tmp->value);
    tmp = tmp->next;
  }
  rra(&a);
  printf("\n reverse rotation \n");
  tmp = a;
  while (tmp)
  {
    printf("[%d]\n", tmp->value);
    tmp = tmp->next;
  }
  return 0;
}
