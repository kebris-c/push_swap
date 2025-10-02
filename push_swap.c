#include "push_swap.h"

static t_move	stackmap(t_stack *a, t_stack *b, t_move (*cost_fn)(t_node *, t_stack *, t_stack *))
{
	t_node	*best;
	t_node	*curr;
	t_move	best_move;
	int		best_cost;
	t_move	move;

	best = NULL;
	curr = b->head;
	best_move.node = NULL;
	best_cost = INT_MAX;
	while (curr)
	{
		move = cost_fn(curr, a, b);
		if (!best || move.total_cost < best_cost)
		{
			best = curr;
			best_cost = move.total_cost;
			best_move = move;
		}
		curr = curr->next;
	}
	return (best_move);
}

static void	perform_rotations(t_stack *a, t_stack *b, t_move move)
{
	int	abs_cost_a;
	int	abs_cost_b;

	abs_cost_a = ft_abs(move.cost_a);
	abs_cost_b = ft_abs(move.cost_b);
	if (move.cost_a >= 0 && move.cost_b >= 0)
		while (abs_cost_a-- > 0 && abs_cost_b-- > 0)
			print_rule_ab(rr, a, b, "rr");
	else if (move.cost_a < 0 && move.cost_b < 0)
		while (abs_cost_a-- > 0 && abs_cost_b-- > 0)
			print_rule_ab(rrr, a, b, "rrr");
	if (move.cost_a > 0)
		while (abs_cost_a-- > 0)
			print_rule_s(ra, a, "ra");
	else if (move.cost_a < 0)
		while (abs_cost_a-- > 0)
			print_rule_s(rra, a, "rra");
	if (move.cost_b > 0)
		while (abs_cost_b-- > 0)
			print_rule_s(rb, b, "rb");
	else if (move.cost_b < 0)
		while (abs_cost_b-- > 0)
			print_rule_s(rrb, b, "rrb");
}

static void	rotate_a_to_min(t_stack *a)
{
	t_node	*curr;
	int		min_ind_pos;

	if (is_sorted(a))
		return ;
	min_ind_pos = 0;
	curr = a->head;
	while (curr->ind)
	{
		if (curr->ind == 0)
			break ;
		min_ind_pos++;
		curr = curr->next;
	}
	if (min_ind_pos <= a->size / 2)
		while (min_ind_pos--)
			print_rule_s(ra, a, "ra");
	else if (min_ind_pos > a->size / 2)
		while (min_ind_pos--)
			print_rule_s(rra, a, "rra");
}

int	push_swap(t_stack *a, t_stack *b, int size_a)
{
	t_move	best_move;
	int		cost;
	int		i;

	if (normalize_index(a, size_a) == EXIT_FAILURE)
		return (ft_err_msg("malloc"));
	find_mark_LIS(a, size_a);
	i = 0;
	while (i < size_a)
	{
		if (a->head && !a->head->keep)
			print_rule_ab(pb, a, b, "pb");
		else
			print_rule_s(ra, a, "ra");
		i++;
	}
	while (b->size > 0)
	{
		best_move = stackmap(a, b, find_pos_calc_cost);
		perform_rotations(a, b, best_move);
		print_rule_ab(pa, a, b, "pa");
	}
	rotate_a_to_min(a);
	return (EXIT_SUCCESS);
}