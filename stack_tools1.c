#include "push_swap.h"

void	ft_stackadd_front(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

void	ft_stackadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = (t_node *)ft_lstlast((void *)*lst);
	new->prev = tmp;
	tmp->next = new;
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
			return (ft_err_msg("malloc"));
		curr->val = values[count++];
		curr->ind = -1;
		curr->keep = FALSE;
		curr->keep_tmp = FALSE;
		curr->prev = prev;
		curr->next = NULL;
		if (prev)
			prev->next = curr;
		else
			(*stack)->head = curr;
		prev = curr;
	}
	return ((*stack)->bottom = curr, EXIT_SUCCESS);
}

t_stack	*stack_new(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	stack->bottom = NULL;
	return (stack);
}