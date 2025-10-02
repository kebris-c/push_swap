#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->size == 0)
		return ;
	tmp = a->head;
	a->head = tmp->next;
	if (a->head)
		a->head->prev = NULL;
	tmp->next = NULL;
	ft_stackadd_front(&b->head, tmp);
	b->size++;
	a->size--;
}

void	ra(t_stack *a)
{
	t_node	*tmp;

	if (a->size <= 1)
		return ;
	tmp = a->head;
	a->head = tmp->next;
	if (a->head)
		a->head->prev = NULL;
	tmp->next = NULL;
	ft_stackadd_back(&a->head, tmp);
}

void	rb(t_stack *b)
{
	t_node	*tmp;

	if (b->size <= 1)
		return ;
	tmp = b->head;
	b->head = tmp->next;
	if (b->head)
		b->head->prev = NULL;
	tmp->next = NULL;
	ft_stackadd_back(&b->head, tmp);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*tmp;

	if (a->size <= 1)
		return ;
	tmp = a->head;
	a->head = tmp->next;
	if (a->head)
		a->head->prev = NULL;
	tmp->next = NULL;
	ft_stackadd_front(&a->head, tmp);
}