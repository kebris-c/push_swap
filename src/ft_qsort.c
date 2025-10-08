/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:46:11 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/06 21:19:09 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(t_qsort_aux *aux, \
		int (*compar)(const void *, const void *))
{
	unsigned char	*arr;
	void			*pivot;
	void			*elem;
	int				i;
	int				j;

	arr = (unsigned char *)aux->base;
	pivot = arr + aux->right * aux->size;
	i = aux->left - 1;
	j = aux->left;
	while (j < aux->right)
	{
		elem = arr + j * aux->size;
		if (compar(elem, pivot) <= 0)
		{
			i++;
			ft_sswap(aux->base + i * aux->size, elem, aux->size);
		}
		j++;
	}
	ft_sswap(arr + (i + 1) * aux->size, pivot, aux->size);
	return (i + 1);
}

static void	qsort_rec(t_qsort_aux *aux, \
		int (*compar)(const void *, const void *))
{
	int			pi;
	t_qsort_aux	left_aux;
	t_qsort_aux	right_aux;

	if (aux->left < aux->right)
	{
		pi = partition(aux, compar);
		left_aux = *aux;
		left_aux.right = pi - 1;
		qsort_rec(&left_aux, compar);
		right_aux = *aux;
		right_aux.left = pi + 1;
		qsort_rec(&right_aux, compar);
	}
}

void	ft_qsort(void *base, size_t nmemb, size_t size, \
	int (*compar)(const void *, const void *))
{
	t_qsort_aux	aux;

	if (!base || nmemb <= 1 || !size || !compar)
		return ;
	aux.base = base;
	aux.size = size;
	aux.left = 0;
	aux.right = (int)nmemb - 1;
	qsort_rec(&aux, compar);
}
