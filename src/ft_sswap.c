/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:50:22 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/06 15:24:56 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sswap(void *a, void *b, size_t size)
{
	unsigned char	tmp;
	unsigned char	*pa;
	unsigned char	*pb;

	if (!a || !b || size == 0)
		return ;
	pa = (unsigned char *)a;
	pb = (unsigned char *)b;
	while (size--)
	{
		tmp = *pa;
		*pa = *pb;
		*pb = tmp;
		pa++;
		pb++;
	}
}
