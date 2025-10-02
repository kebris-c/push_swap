#include "push_swap.h"

static void	index_per_every_node(int *arr, t_stack *stack, int size)
{
	t_node	*curr;
	int		left;
	int		right;
	int		mid;

	curr = stack->head;
	while (curr)
	{
		left = 0;
		right = size - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (arr[mid] == curr->val)
			{
				curr->ind = mid;
				break ;
			}
			else if (arr[mid] < curr->val)
				left = mid + 1;
			else
				right = mid - 1;
		}
		curr = curr->next;
	}
}

int	normalize_index(t_stack *stack, int size)
{
	t_node	*curr;
	int		i;
	int		*arr;

	arr = malloc(sizeof(*arr) * size);
	if (!arr)
		return (EXIT_FAILURE);
	curr = stack->head;
	i = 0;
	while (curr)
	{
		arr[i] = curr->val;
		curr = curr->next;
		i++;
	}
	ft_qsort(arr, size, sizeof(int), ft_intcmp);
	index_per_every_node(arr, stack, size);
	free(arr);
	return (EXIT_SUCCESS);
}