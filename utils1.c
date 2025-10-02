#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	if (!stack)
		return ;
	curr = stack->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(stack);
}

int	safe_exit(int argc, char **numbers, int exit_flag)
{
	if (argc == 2)
		ft_free_matrix(numbers);
	if (exit_flag == EXIT_FAILURE)
		return (ft_err_msg());
	return (EXIT_SUCCESS);
}

static t_bool	has_duplicated(int *values, int size)
{
	int	curr;
	int	i;
	int	j;

	if (size == 1)
		return (FALSE);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (values[i] == values[j] && i != j)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	parse_argv_count(int argc, char **argv, char ***numbers, t_stack **a)
{
	int	count;

	if (argc == 2)
	{
		*numbers = ft_split(argv[1], ' ');
		if (!*numbers)
			return (EXIT_FAILURE);
	}
	else
		*numbers = argv + 1;
	count = 0;
	while ((*numbers)[count])
		count++;
	if (count == 0)
		return (safe_exit(argc, *numbers, EXIT_FAILURE));
	(*a)->size = count;
	return (EXIT_SUCCESS);
}

int	parse_argv(int argc, char **argv, t_stack **a, t_stack **b)
{
	int		i;
	int		*values;
	char	**numbers;

	if (parse_argv_count(argc, argv, &numbers, a) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	values = (int *)malloc(sizeof(*values) * (*a)->size);
	if (!values)
		return (safe_exit(argc, numbers, EXIT_FAILURE));
	i = 0;
	while (numbers[i] && i < (*a)->size)
	{
		if (ft_safe_atoi((const char *)numbers[i], &values[i]) == EXIT_FAILURE)
			return (free(values), safe_exit(argc, numbers, EXIT_FAILURE));
		i++;
	}
	if (has_duplicated(values, (*a)->size))
		return (free(values), safe_exit(argc, numbers, EXIT_FAILURE));
	if (mount_stack(a, values) == EXIT_FAILURE)
		return (free(values), safe_exit(argc, numbers, EXIT_FAILURE));
	return (free(values), safe_exit(argc, numbers, EXIT_SUCCESS));
}