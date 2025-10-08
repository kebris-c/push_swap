/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:10:58 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/06 20:23:58 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stacklast(t_node *lst)
{
	t_node	*curr;

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
	ft_sswap(&a->head->val, &a->head->next->val, sizeof(int));
	ft_sswap(&a->head->ind, &a->head->next->ind, sizeof(int));
	ft_sswap(&a->head->keep, &a->head->next->keep, sizeof(t_bool));
}

void	sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_sswap(&b->head->val, &b->head->next->val, sizeof(int));
	ft_sswap(&b->head->ind, &b->head->next->ind, sizeof(int));
	ft_sswap(&b->head->keep, &b->head->next->keep, sizeof(t_bool));
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
	else
		b->bottom = NULL;
	tmp->next = NULL;
	ft_stackadd_front(a, tmp);
	a->size++;
	b->size--;
}
