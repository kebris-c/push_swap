#include "push_swap.h"

void	rrb(t_stack *b)
{
	t_node	*tmp;

	if (b->size <= 1)
		return ;
	tmp = b->head;
	b->head = tmp->next;
	if (b->head)
		b->head->prev = NULL;
	tmp->next = NULL;
	ft_stackadd_front(&b->head, tmp);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}