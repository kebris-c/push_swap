/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:37:24 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 21:44:29 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

typedef struct s_node
{
	int				val;
	int				ind;
	t_bool			keep;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*bottom;
}	t_stack;

typedef struct s_lis_aux
{
	t_node	*best_start;
	int		max_length;
	int		lis_len;
}	t_lis_aux;

typedef struct s_move
{
	t_node	*node;
	int		cost_a;
	int		cost_b;
	int		total_cost;
}	t_move;

typedef struct s_qsort_aux
{
	void	*base;
	size_t	size;
	int		left;
	int		right;
}	t_qsort_aux;

typedef void	(*t_rule_fn_s)(t_stack *);

typedef void	(*t_rule_fn_ab)(t_stack *, t_stack *);

static inline void	print_rule_s(t_rule_fn_s fn, t_stack *s, const char *rule)
{
	fn(s);
	ft_printf("%s\n", rule);
}

static inline void	print_rule_ab(t_rule_fn_ab fn, t_stack *a, \
		t_stack *b, const char *rule)
{
	fn(a, b);
	ft_printf("%s\n", rule);
}

int			push_swap(t_stack *a, t_stack *b, int size);
int			simple_push_swap(t_stack *a, t_stack *b, int size);
int			ft_safe_atoi(const char *str, int *ptr);
int			ft_base_pos(char nb, const char *base);
int			parse_argv(int argc, char **argv, t_stack **a);
int			mount_stack(t_stack **a, int *values);
int			ft_cmp_int(const void *a, const void *b);
int			normalize_index(t_stack *stack, int size);
int			ft_abs(int x);
int			find_push_lis(t_stack *a, t_stack *b, int size);
char		*ft_get_base(int base);
void		free_stack(t_stack *stack);
void		ft_sswap(void *a, void *b, size_t size);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		ft_stackadd_front(t_stack *stack, t_node *newnode);
void		ft_stackadd_back(t_stack *stack, t_node *newnode);
void		ft_qsort(void *base, size_t nmemb, size_t size, \
		int (*compar)(const void *, const void *));
t_move		find_pos_calc_cost(t_node *node_b, t_stack *a, t_stack *b);
t_stack		*stack_new(void);
t_node		*ft_stacklast(t_node *lst);
t_bool		is_sorted(t_stack *stack);
long long	ft_strtoll(char *nptr, char **endptr, int base);

#endif
