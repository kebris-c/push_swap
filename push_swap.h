#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct	s_node
{
	int				val;
	int				ind;
	t_bool			keep;
	t_bool			keep_tmp;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct	s_stack
{
	int		size;
	t_node	*head;
	t_node	*bottom;
}	t_stack;

typedef struct	s_lis_aux
{
	t_node	*best_start;
	int		max_length;
	int		lis_len;
	int		last_ind;
}	t_lis_aux;

typedef struct	s_move
{
	t_node	*node;
	int		cost_a;
	int		cost_b;
	int		total_cost;
}	t_move;

typedef void	(*t_rule_fn_s)(t_stack *);

typedef void	(*t_rule_fn_ab)(t_stack *, t_stack *);

static inline void	print_rule_s(t_rule_fn_s fn, t_stack *s, const char *rule)
{
    fn(s);
    ft_printf("%s\n", rule);
}

static inline void	print_rule_ab(t_rule_fn_ab fn, t_stack *a, t_stack *b, const char *rule)
{
    fn(a, b);
    ft_printf("%s\n", rule);
}

int			push_swap(t_stack *a, t_stack *b, int size);
int			simple_push_swap(t_stack *a, t_stack *b, int size);
int			ft_safe_atoi(const char *str, int *ptr);
int			ft_base_pos(char nb, char *base);
int			parse_argv(int argc, char **argv, t_stack **a);
int			safe_exit(int argc, char **numbers, int exit_flag);
int			ft_err_msg(char *flag);
int			mount_stack(t_stack **a, int *values);
int			ft_intcmp(const void *a, const void *b);
int			normalize_index(t_stack *stack, int size);
int			ft_abs(int x);
char		*ft_get_base(int base);
void		find_mark_LIS(t_stack *stack, int size);
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
void		*ft_lstlast(void *lst);
void		ft_stackadd_front(t_node **lst, t_node *new);
void		ft_stackadd_back(t_node **lst, t_node *new);
t_move		find_pos_calc_cost(t_node *node_b, t_stack *a, t_stack *b);
t_stack		*stack_new(void);
t_bool		is_sorted(t_stack *stack);
long long	ft_strtoll(char *nptr, char **endptr, int base);

#endif