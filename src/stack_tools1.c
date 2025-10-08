/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:10:42 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/06 20:23:30 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_front(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	new->prev = NULL;
	new->next = stack->head;
	if (stack->head)
		stack->head->prev = new;
	stack->head = new;
	if (!stack->bottom)
		stack->bottom = new;
}

void	ft_stackadd_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	new->next = NULL;
	if (!stack->head)
	{
		new->prev = NULL;
		stack->head = new;
		stack->bottom = new;
		return ;
	}
	last = stack->bottom;
	last->next = new;
	new->prev = last;
	stack->bottom = new;
}

int	mount_stack(t_stack **stack, int *values)
{
	t_node	*curr;
	t_node	*prev;
	int		count;

	count = 0;
	prev = NULL;
	while (count < (*stack)->size)
	{
		curr = (t_node *)malloc(sizeof(*curr));
		if (!curr)
			return (free_stack((*stack)), ft_err_msg("malloc"));
		curr->val = values[count++];
		curr->ind = -1;
		curr->keep = FALSE;
		curr->prev = prev;
		curr->next = NULL;
		if (prev)
			prev->next = curr;
		else
			(*stack)->head = curr;
		prev = curr;
	}
	(*stack)->size = count;
	return ((*stack)->bottom = curr, EXIT_SUCCESS);
}

t_stack	*stack_new(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	stack->bottom = NULL;
	return (stack);
}
