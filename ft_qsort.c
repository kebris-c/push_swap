#include "push_swap.h"

static int	partition(void *base, size_t size, int left, int right, \
	int (*compar)(const void *, const void *))
{
	unsigned char	*arr;
	void			*pivot;
	void			*elem;
	int				i;
	int				j;

	arr = (unsigned char *)base;
	pivot = arr + right * size;
	i = left - 1;
	j = left;
	while (j < right)
	{
		elem = arr + j * size;
		if (compar(elem, pivot) <= 0)
		{
			i++;
			ft_sswap(base + i * size, elem, size);
		}
		j++;
	}
	ft_sswap(arr + (i + 1) * size, pivot, size);
	return (i + 1);
}

static void	qsort_rec(void *base, size_t size, int left, int right, \
	int (*compar)(const void *, const void *))
{
	int	pi;

	if (left < right)
	{
		pi = partition(base, size, left, right, compar);
		qsort_rec(base, size, left, pi - 1, compar);
		qsort_rec(base, size, pi + 1, right, compar);
	}
}

void	ft_qsort(void *base, size_t nmemb, size_t size, \
	int (*compar)(const void *, const void *))
{
	int				left;
	int				right;

	if (!base || !*base || nmemb <= 1 || !size || !compar)
		return ;
	left = 0;
	right = (int)nmemb - 1;
	qsort_rec(base, size, left, right, compar);
}