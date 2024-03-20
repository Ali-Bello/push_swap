#include <stdio.h>
#include "push_swap.h"

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

int main() {
  t_stack *head, *tmp;
  t_stack x;
  t_stack y;
  t_stack z;

  head = 0;
  x.value = 2;
  y.value = 1;
  z.value = 3;

  add_node(&head, &x);
  add_node(&head, &y);
  add_node(&head, &z);
  tmp = head;
  while (tmp)
  {
    printf("[%d]\n", tmp->value);
    tmp = tmp->next;
  }
  sa(&head);
  tmp = head;
  printf("\nswapped \n\n");

  while (tmp)
  {
    printf("[%d]\n", tmp->value);
    tmp = tmp->next;
  }
  return 0;
}
