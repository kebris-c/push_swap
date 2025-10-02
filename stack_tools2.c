#include "push_swap.h"

void	*ft_lstlast(void *lst)
{
	void	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	sa(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_sswap(a->head->val, a->head->next->val, sizeof(*a->head->val));
	ft_sswap(a->head->ind, a->head->next->ind, sizeof(*a->head->ind));
	ft_sswap(a->head->keep, a->head->next->keep, sizeof(*a->head->keep));
	ft_sswap(a->head->keep_tmp, a->head->next->keep_tmp, sizeof(*a->head->keep_tmp));
}

void	sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_sswap(b->head->val, b->head->next->val, sizeof(*b->head->val));
	ft_sswap(b->head->ind, b->head->next->ind, sizeof(*b->head->ind));
	ft_sswap(b->head->keep, b->head->next->keep, sizeof(*b->head->keep));
	ft_sswap(b->head->keep_tmp, b->head->next->keep_tmp, sizeof(*b->head->keep_tmp));
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->head;
	b->head = tmp->next;
	if (b->head)
		b->head->prev = NULL;
	tmp->next = NULL;
	ft_stackadd_front(&a->head, tmp);
	a->size++;
	b->size--;
}