/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:36:53 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 21:04:56 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_lis(t_lis_aux *aux, t_stack *stack, t_node *curr, int size)
{
	int	i;
	int	last_ind;

	aux->lis_len = 0;
	last_ind = -1;
	i = 0;
	while (i++ < size)
	{
		if (!curr)
			return ;
		if (curr->keep)
			curr->keep = FALSE;
		if (curr->ind > last_ind)
		{
			curr->keep = TRUE;
			last_ind = curr->ind;
			aux->lis_len++;
		}
		if (curr->next)
			curr = curr->next;
		else
			curr = stack->head;
	}
}

static int	push_lis(t_stack *a, t_stack *b, int size)
{
	t_node	*curr;

	curr = a->head;
	while (size--)
	{
		if (curr->keep == 1)
			print_rule_s(ra, a, "ra");
		else if (curr->keep == 0)
			print_rule_ab(pb, a, b, "pb");
		curr = a->head;
	}
	return (EXIT_SUCCESS);
}

int	find_push_lis(t_stack *a, t_stack *b, int size)
{
	t_lis_aux	aux;
	t_node		*start;
	t_node		*curr;

	aux.best_start = NULL;
	aux.max_length = 0;
	start = a->head;
	while (start)
	{
		curr = start;
		try_lis(&aux, a, curr, size);
		if (aux.lis_len > aux.max_length)
		{
			aux.max_length = aux.lis_len;
			aux.best_start = start;
		}
		start = start->next;
	}
	if (!aux.best_start)
		return (EXIT_FAILURE);
	try_lis(&aux, a, aux.best_start, size);
	if (aux.lis_len != aux.max_length)
		return (EXIT_FAILURE);
	return (push_lis(a, b, size));
}
