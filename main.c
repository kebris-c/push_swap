#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		exit_flag;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	a = stack_new();
	if (!a)
		return (ft_err_msg("malloc"));
	if (parse_argv(argc, argv, &a) == EXIT_FAILURE)
		return (free_stack(a), EXIT_FAILURE);
	if (is_sorted(a))
		return (free_stack(a), EXIT_SUCCESS);
	b = stack_new();
	if (!b)
		return (free_stack(a), ft_err_msg("malloc"));
	if (a->size <= 5)
		exit_flag = simple_push_swap(a, b, a->size);
	else
		exit_flag = push_swap(a, b, a->size);
	return (free_stack(a), free_stack(b), exit_flag);
}