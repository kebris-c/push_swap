/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:49:20 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 21:45:52 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move	stackmap(t_stack *a, t_stack *b, \
		t_move (*cost_fn)(t_node *, t_stack *, t_stack *))
{
	t_node	*best;
	t_node	*curr;
	int		best_cost;
	t_move	best_m;
	t_move	move;

	best = NULL;
	curr = b->head;
	best_m.node = NULL;
	best_cost = INT_MAX;
	while (curr)
	{
		move = cost_fn(curr, a, b);
		if (!best || move.total_cost < best_cost)
		{
			best = curr;
			best_cost = move.total_cost;
			best_m = move;
		}
		curr = curr->next;
	}
	return (best_m);
}

static void	perform_rotations(t_stack *a, t_stack *b, t_move m)
{
	int	abs_cost_a;
	int	abs_cost_b;

	abs_cost_a = ft_abs(m.cost_a);
	abs_cost_b = ft_abs(m.cost_b);
	while (m.cost_a > 0 && m.cost_b > 0 && abs_cost_a-- > 0 && abs_cost_b-- > 0)
		print_rule_ab(rr, a, b, "rr");
	while (m.cost_a < 0 && m.cost_b < 0 && abs_cost_a-- > 0 && abs_cost_b-- > 0)
		print_rule_ab(rrr, a, b, "rrr");
	if (m.cost_a > 0)
		while (abs_cost_a-- > 0)
			print_rule_s(ra, a, "ra");
	else if (m.cost_a < 0)
		while (abs_cost_a-- > 0)
			print_rule_s(rra, a, "rra");
	if (m.cost_b > 0)
		while (abs_cost_b-- > 0)
			print_rule_s(rb, b, "rb");
	else if (m.cost_b < 0)
		while (abs_cost_b-- > 0)
			print_rule_s(rrb, b, "rrb");
}

static int	return_to_a(t_stack *a, t_stack *b)
{
	t_move	best_move;

	while (b->size > 0)
	{
		best_move = stackmap(a, b, find_pos_calc_cost);
		perform_rotations(a, b, best_move);
		print_rule_ab(pa, a, b, "pa");
	}
	return (EXIT_SUCCESS);
}

static int	rotate_a_to_min(t_stack *a)
{
	t_node	*curr;
	int		min_ind_pos;

	if (!a || !a->head || is_sorted(a))
		return (EXIT_FAILURE);
	min_ind_pos = 0;
	curr = a->head;
	while (curr)
	{
		if (curr->ind == 0)
			break ;
		min_ind_pos++;
		curr = curr->next;
	}
	if (!curr)
		return (EXIT_FAILURE);
	if (min_ind_pos <= a->size / 2)
		while (min_ind_pos--)
			print_rule_s(ra, a, "ra");
	else
		while (min_ind_pos++ < a->size)
			print_rule_s(rra, a, "rra");
	return (EXIT_SUCCESS);
}

int	push_swap(t_stack *a, t_stack *b, int size)
{
	if (normalize_index(a, size) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (find_push_lis(a, b, size) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (return_to_a(a, b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (rotate_a_to_min(a) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
