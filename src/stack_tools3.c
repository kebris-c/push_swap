/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:10:55 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/05 16:37:04 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else
		a->bottom = NULL;
	tmp->next = NULL;
	ft_stackadd_front(b, tmp);
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
	ft_stackadd_back(a, tmp);
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
	ft_stackadd_back(b, tmp);
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
	tmp = a->bottom;
	a->bottom = tmp->prev;
	if (a->bottom)
		a->bottom->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(a, tmp);
}
