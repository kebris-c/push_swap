#include "push_swap.h"

int	ft_safe_atoi(const char *str, int *ptr)
{
	char		*end;
	long long	val;

	errno = 0;
	val = ft_strtoll(str, &end, 10);
	if (*end != '\0' || errno == ERANGE || val < INT_MIN || val > INT_MAX)
		return (EXIT_FAILURE);
	*ptr = (int)val;
	return (EXIT_SUCCESS);
}