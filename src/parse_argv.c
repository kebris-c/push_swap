/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:11:04 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/07 15:21:46 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	safe_exit(int argc, char **numbers, int exit_flag)
{
	if (argc == 2)
		ft_free_matrix(numbers);
	if (exit_flag == EXIT_FAILURE)
		return (ft_err_msg(NULL));
	return (EXIT_SUCCESS);
}

static t_bool	has_duplicated(int *values, int size)
{
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

static int	parse_argv_count(int argc, char **argv, \
		char ***numbers, t_stack **a)
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

int	parse_argv(int argc, char **argv, t_stack **a)
{
	int		i;
	int		*values;
	char	**numbers;

	if (parse_argv_count(argc, argv, &numbers, a) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	values = (int *)ft_calloc((*a)->size, sizeof(*values));
	if (!values)
		return (safe_exit(argc, numbers, EXIT_FAILURE));
	i = 0;
	while (numbers[i] && i++ < (*a)->size)
		if (ft_safe_atoi((const char *)numbers[i - 1], \
					&values[i - 1]) == EXIT_FAILURE)
			return (free(values), safe_exit(argc, numbers, EXIT_FAILURE));
	if (has_duplicated(values, (*a)->size))
		return (free(values), safe_exit(argc, numbers, EXIT_FAILURE));
	if (mount_stack(a, values) == EXIT_FAILURE)
		return (free(values), safe_exit(argc, numbers, EXIT_FAILURE));
	return (free(values), safe_exit(argc, numbers, EXIT_SUCCESS));
}
