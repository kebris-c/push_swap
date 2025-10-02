#include "push_swap.h"

void	ft_sswap(void *a, void *b, size_t size)
{
	unsigned char	tmp;
	unsigned char	*pa;
	unsigned char	*pb;

	pa = (unsigned char *)a;
	pb = (unsigned char *)b;
	while (size)
	{
		tmp = *pa;
		*pa = *pb;
		*pb = tmp;
		*pa++;
		*pb++;
		size--;
	}
}