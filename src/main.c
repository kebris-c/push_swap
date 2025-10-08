/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:10:31 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 21:46:47 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	db_nodes_stack(t_stack *s, int stack)
{
	t_node	*curr;
	int		n_nodes;

	printf("\tstack(%c):\n", stack);
	n_nodes = 0;
	curr = s->head;
	while (curr)
	{
		printf("\t\tnode(%d):\n", n_nodes);
		printf("\t\t\tval: %d\n", curr->val);
		printf("\t\t\tind: %d\n", curr->ind);
		printf("\t\t\tkeep: %d\n", curr->keep);
		n_nodes++;
		curr = curr->next;
	}
	printf("\t\tTotal of nodes: %d\n", n_nodes);
	printf("\t\tSupposed stack->size: %d\n\n", s->size);
}

void	ft_debugger(t_stack *a, t_stack *b)
{
	db_nodes_stack(a, 'a');
	db_nodes_stack(b, 'b');
}*/

static int	err_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		exit_flag;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	a = stack_new();
	if (!a)
		return (err_msg());
	if (parse_argv(argc, argv, &a) == EXIT_FAILURE)
		return (free_stack(a), err_msg());
	if (is_sorted(a))
		return (free_stack(a), EXIT_SUCCESS);
	b = stack_new();
	if (!b)
		return (free_stack(a), err_msg());
	if (a->size <= 5)
		exit_flag = simple_push_swap(a, b, a->size);
	else
		exit_flag = push_swap(a, b, a->size);
	if (exit_flag == EXIT_FAILURE)
		return (free_stack(a), free_stack(b), err_msg());
	return (free_stack(a), free_stack(b), exit_flag);
}
