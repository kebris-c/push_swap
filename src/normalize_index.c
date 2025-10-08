/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:10:34 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 15:26:51 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_per_every_node(int *arr, t_stack *stack, int size)
{
	t_node	*curr;
	int		i;

	curr = stack->head;
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			if (curr->val == arr[i])
			{
				curr->ind = i;
				break ;
			}
			i++;
		}
		if (curr->ind == -1)
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}

static int	*check_size_malloc_arr(t_stack *stack, int *size)
{
	t_node	*curr;
	int		*arr;
	int		actual_size;

	actual_size = 0;
	curr = stack->head;
	while (curr)
	{
		actual_size++;
		curr = curr->next;
	}
	if (actual_size <= 0)
		return (NULL);
	if (actual_size != (*size))
		(*size) = actual_size;
	arr = malloc(sizeof(*arr) * (*size));
	return (arr);
}

int	normalize_index(t_stack *stack, int size)
{
	t_node	*curr;
	int		i;
	int		*arr;

	arr = check_size_malloc_arr(stack, &size);
	if (!arr)
		return (EXIT_FAILURE);
	curr = stack->head;
	i = 0;
	while (curr)
	{
		arr[i++] = curr->val;
		curr = curr->next;
	}
	ft_qsort((void *)arr, (size_t)size, sizeof(int), ft_cmp_int);
	if (index_per_every_node(arr, stack, size) == EXIT_FAILURE)
		return (free(arr), EXIT_FAILURE);
	free(arr);
	stack->size = size;
	return (EXIT_SUCCESS);
}
