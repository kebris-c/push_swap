/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_calc_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:43:49 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 20:59:25 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*highest_ind_node_pos(t_stack *s)
{
	t_node	*curr;
	int		highest_ind;

	highest_ind = -1;
	curr = s->head;
	while (curr)
	{
		if (curr->ind > highest_ind)
			highest_ind = curr->ind;
		curr = curr->next;
	}
	curr = s->head;
	while (curr)
	{
		if (curr->ind == highest_ind)
			break ;
		curr = curr->next;
	}
	return (curr);
}

static int	node_pos_in_stack(t_stack *s, t_node *node)
{
	t_node	*curr;
	int		pos;

	curr = s->head;
	pos = 0;
	while (curr)
	{
		if (curr == node)
			break ;
		pos++;
		curr = curr->next;
	}
	return (pos);
}

static int	find_pos(t_move move, t_stack *a)
{
	t_node	*curr;
	t_node	*best_fit;
	t_node	*node_a;

	best_fit = NULL;
	curr = a->head;
	while (curr)
	{
		if (curr->ind > move.node->ind)
			if (!best_fit || curr->ind < best_fit->ind)
				best_fit = curr;
		curr = curr->next;
	}
	if (best_fit)
		node_a = best_fit;
	else
		node_a = highest_ind_node_pos(a);
	return (node_pos_in_stack(a, node_a));
}

static void	calc_cost(int pos, int size, t_move *move, int flag)
{
	if (flag == 'a')
	{
		if (pos <= size / 2)
			move->cost_a = pos;
		else
			move->cost_a = pos - size;
	}
	else if (flag == 'b')
	{
		if (pos <= size / 2)
			move->cost_b = pos;
		else
			move->cost_b = pos - size;
	}
}

t_move	find_pos_calc_cost(t_node *node_b, t_stack *a, t_stack *b)
{
	t_move	move;
	int		pos_a;
	int		pos_b;

	move.node = node_b;
	pos_a = find_pos(move, a);
	calc_cost(pos_a, a->size, &move, 'a');
	pos_b = node_pos_in_stack(b, move.node);
	calc_cost(pos_b, b->size, &move, 'b');
	move.total_cost = ft_abs(move.cost_a) + ft_abs(move.cost_b);
	return (move);
}
