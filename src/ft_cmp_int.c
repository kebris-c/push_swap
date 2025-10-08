/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:45:00 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/05 12:45:34 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cmp_int(const void *a, const void *b)
{
	int	ia;
	int	ib;

	if (!a || !b)
		return (0);
	ia = *(const int *)a;
	ib = *(const int *)b;
	return (ia - ib);
}
