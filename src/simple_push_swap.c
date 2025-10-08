/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:10:39 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 21:06:40 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->val;
	second = a->head->next->val;
	third = a->bottom->val;
	if (first > second && second < third && first < third)
		print_rule_s(sa, a, "sa");
	else if (first > second && second > third)
	{
		print_rule_s(sa, a, "sa");
		print_rule_s(rra, a, "rra");
	}
	else if (first > second && second < third && first > third)
		print_rule_s(ra, a, "ra");
	else if (first < second && second > third && first < third)
	{
		print_rule_s(sa, a, "sa");
		print_rule_s(ra, a, "ra");
	}
	else if (first < second && second > third && first > third)
		print_rule_s(rra, a, "rra");
}

static void	rotate_smallest(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos-- > 0)
			print_rule_s(ra, a, "ra");
	else
		while (pos++ < a->size)
			print_rule_s(rra, a, "rra");
}

static void	push_smallest_nums(t_stack *a, t_stack *b)
{
	t_node	*smallest;
	t_node	*curr;
	int		pos;
	int		i;

	curr = a->head;
	smallest = a->head;
	pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->val < smallest->val)
		{
			smallest = curr;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	rotate_smallest(a, pos);
	print_rule_ab(pb, a, b, "pb");
}

int	simple_push_swap(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		if (a->head->val > a->bottom->val)
			print_rule_s(sa, a, "sa");
	if (size == 3)
		sort_three(a);
	if (size >= 4)
	{
		while (a->size > 3)
			push_smallest_nums(a, b);
		sort_three(a);
		while (b->size > 0)
			print_rule_ab(pa, a, b, "pa");
	}
	return (EXIT_SUCCESS);
}
