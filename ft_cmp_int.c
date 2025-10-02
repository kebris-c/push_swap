#include "push_swap.h"

int	ft_cmp_int(const void *a, const void *b)
{
	int	ia;
	int	ib;

	if (!a || !b || !*a || !*b)
		return (0);
	ia = *(const int *)a;
	ib = *(const int *)b;
	return (ia - ib);
}