#include "push_swap.h"

static void	circular_walking(t_lis_aux *aux, t_stack *stack, t_node *curr, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (curr->keep_tmp)
			curr->keep_tmp = FALSE;
		if (curr->ind > aux->last_ind)
		{
			curr->keep_tmp = TRUE;
			aux->last_ind = curr->ind;
			aux->lis_len++;
		}
		if (curr->next)
			curr = curr->next;
		else
			curr = stack->head;
	}
}

static void	true_LIS_mark(t_lis_aux aux, t_stack *stack, t_node *curr, int size)
{
	int	i;

	if (aux.best_start)
	{
		aux.lis_len = 0;
		aux.last_ind = -1;
		circular_walking(&aux, stack, aux.best_start, size);
		curr = aux.best_start;
		i = 0;
		while (i++ < size)
		{
			if (curr->keep_tmp && curr->ind > aux.last_ind)
			{
				curr->keep = TRUE;
				aux.last_ind = curr->ind;
			}
			if (curr->next)
				curr = curr->next;
			else
				curr = stack->head;
		}
	}
}

void	find_mark_LIS(t_stack *stack, int size)
{
	t_lis_aux	aux;
	t_node		*start;
	t_node		*curr;

	aux.best_start = NULL;
	aux.max_length = 0;
	start = stack->head;
	while (start)
	{
		aux.lis_len = 0;
		aux.last_ind = -1;
		curr = start;
		circular_walking(&aux, stack, curr, size);
		if (aux.lis_len > aux.max_length)
		{
			aux.max_length = aux.lis_len;
			aux.best_start = start;
		}
		start = start->next;
	}
	true_LIS_mark(aux, stack, curr, size);
}