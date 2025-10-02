#include "push_swap.h"

int	ft_err_msg(char *flag)
{
	ft_putstr_fd("Error\n", 2);
	if (!flag)
		return (EXIT_FAILURE);
	if (ft_strcmp(flag, "argc") == 0)
		ft_putstr_fd("Bad arguments\n", 2);
	else
		perror(flag);
	return (EXIT_FAILURE);
}