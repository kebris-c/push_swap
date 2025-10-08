/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:11:01 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 15:22:09 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *b)
{
	t_node	*tmp;

	if (b->size <= 1)
		return ;
	tmp = b->bottom;
	b->bottom = tmp->prev;
	if (b->bottom)
		b->bottom->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(b, tmp);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

t_bool	is_sorted(t_stack *stack)
{
	t_node	*curr;

	if (!stack)
		return (FALSE);
	curr = stack->head;
	while (curr && curr->next)
	{
		if (!(curr->val < curr->next->val))
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	if (!stack)
		return ;
	curr = stack->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(stack);
}
